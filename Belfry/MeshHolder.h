#pragma once

#include <vector>
#include <SOIL.h>
#include "BlfComponent.h"
#include "Mesh.h"
#include "Shader.h"
#include "BlfWorld.h"
#include "TextureLoader.h"

class MeshHolder : public BlfComponent {

public:
  const void awake() {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * sizeof(Vertex), &mesh->vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indices.size() * sizeof(unsigned int), &mesh->indices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);
    glEnableVertexAttribArray(0);
   
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, textureCoordinates));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
    
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    TextureLoader::load(mesh->texture);

    auto fppActor = BlfWorld::instance().getBlfObjectByTag("FppActor");
    _camera = fppActor->getComponent<Camera>();
    _transform = parent()->getComponent<Transform>();
  }

  const void update() {
    draw();

   /* if (parent()->tag().compare("FppActor")) {
      draw();
    }
    else {
      transformSelf();
    }*/
  }

  const void lateUpdate() {

  }

  Mesh* mesh;
  Shader* shader;

private:
  void transformSelf() {
    glPushMatrix();
    
    glLoadIdentity();

    auto position = _transform->position;
    glTranslatef(position.x, position.y, position.z);

    auto rotation = _transform->rotation;
    auto angle = _transform->rotationAngle;
    glRotatef(angle, rotation.x, rotation.y, rotation.z);

    auto scale = _transform->scale;
    glScalef(scale.x, scale.y, scale.z);

    draw();

    glPopMatrix();
  }

  void draw() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mesh->texture.id);
    glUniform1i(glGetUniformLocation(shader->id(), "Texture0"), 0);

    shader->use();

    //-------------------------
    GLuint modelLoc = glGetUniformLocation(shader->id(), "model");
    GLuint viewLoc = glGetUniformLocation(shader->id(), "view");
    GLuint projLoc = glGetUniformLocation(shader->id(), "projection");

    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(_camera->projection()));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(_camera->view()));
    //-------------------------

    glBindVertexArray(vao);

    //-------------------------
    //glm::mat4 modelTrans;
    //glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelTrans));
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(_transform->transformModel));
    //-------------------------

    //glDrawArrays(GL_TRIANGLES, 0, (GLuint)mesh->vertices.size() * 5); // 5x GLfloat
    glDrawElements(GL_TRIANGLES, mesh->indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
  }

  GLuint vao;
  GLuint vbo;
  GLuint ebo;
  Camera* _camera;
  Transform* _transform;
};

