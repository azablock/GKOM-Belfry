#pragma once

#include <vector>
#include <SOIL.h>
#include "BlfComponent.h"
#include "Mesh.h"
#include "Shader.h"
#include "GlWindowContainer.h"
#include "BlfWorld.h"

class MeshHolder : public BlfComponent {
public:

  const void awake() {
    //jak dobrze inicjalizowac shaderProgram
    //shader = ?

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * sizeof(Vertex), &mesh->vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indices.size() * sizeof(unsigned int), &mesh->indices[0], GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
   
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, normal));
    
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, textureCoordinates));

    glBindVertexArray(0);

    cout << "offsetof(Vertex, normal): " << offsetof(Vertex, normal) << endl;
    cout << "offsetof(Vertex, textureCoordinates): " << offsetof(Vertex, textureCoordinates) << endl;

    		// Set the texture wrapping parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// Set texture filtering parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height;
    unsigned char* image = SOIL_load_image("Brick1.png", &width, &height, 0, SOIL_LOAD_RGB);


    cout << SOIL_last_result() << endl;

    if (image == nullptr)
      throw exception("Failed to load texture file");

    glGenTextures(1, &texture);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    // freeing unnecessary texture stuff
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);


    //syf
    auto obj = BlfWorld::instance()->getBlfObjectByTag("WindowContainer");
    windowContainer = obj->getComponent<GLWindowContainer>();
  }

  const void update() {
    /*
    //unsigned int diffuseNr = 1;
    //unsigned int specularNr = 1;

    //for (unsigned int i = 0; i < mesh->textures.size(); i++) {
    //  glActiveTexture(GL_TEXTURE0 + i); // activate proper texture unit before binding
    //                                    // retrieve texture number (the N in diffuse_textureN)
    //  string number;
    //  string name = mesh->textures[i].type;

    //  if (name == "texture_diffuse")
    //    number = std::to_string(diffuseNr++);
    //  else if (name == "texture_specular")
    //    number = std::to_string(specularNr++);

    //  shader->setFloat(("material." + name + number).c_str(), i);
    //  glBindTexture(GL_TEXTURE_2D, mesh->textures[i].id);
    //}

    //// draw mesh
    //glBindVertexArray(vao);
    //glDrawElements(GL_TRIANGLES, mesh->indices.size(), GL_UNSIGNED_INT, 0);
    //glBindVertexArray(0);

    //glActiveTexture(GL_TEXTURE0);
    
    //shader->use();
    //===============================================================================
    */

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform1i(glGetUniformLocation(shader->id(), "Texture0"), 0);
    shader->use();

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, mesh->indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

   // glfwSwapBuffers(windowContainer->window());
  }

  Mesh* mesh;
  Shader* shader;

  unsigned int vao;
  unsigned int vbo;
  unsigned int ebo;

  GLuint texture;

  GLWindowContainer* windowContainer;
};

