#pragma once

#include "MeshFactory.h"

class RectangleMeshFactory : public MeshFactory {
public:
  Mesh* newInstance(std::string imagePath) {
    auto mesh = new Mesh();
    
   // GLfloat vertices[] = {
			////position			      // color	    		// texture
			// 0.25f,  0.5f,  0.0f,	1.0f, 0.0f, 0.0f,	1.0f,  1.0f,	
			//-0.75f,  0.5f,  0.0f,	0.0f, 1.0f, 0.0f,	1.0f,  0.0f,
			//-0.25f, -0.5f,  0.0f,	0.0f, 0.0f, 1.0f,	0.0f,  0.0f,
			// 0.75f, -0.5f,  0.0f,	1.0f, 0.0f, 1.0f,	0.0f,  1.0f
   // };


    //todo to be refactored
    std::vector<Vertex> vertices;
    
    GLfloat textureCoordMultiplier = 10.0f;

    Vertex vertex1;
    vertex1.position = glm::vec3(1.0f, 1.0f, 0.0f);
   // vertex1.normal = glm::vec3(1.0f, 0.0f, 0.0f);
    vertex1.textureCoordinates = glm::vec2(1.0f, textureCoordMultiplier);

    Vertex vertex2;
    vertex2.position = glm::vec3(-1.0f, 1.0f, 0.0f);
   // vertex2.normal = glm::vec3(0.0f, 1.0f, 0.0f);
    vertex2.textureCoordinates = glm::vec2(textureCoordMultiplier, 0.0f);

    Vertex vertex3;
    vertex3.position = glm::vec3(-1.0f, -1.0f, 0.0f);
   // vertex3.normal = glm::vec3(0.0f, 0.0f, 1.0f);
    vertex3.textureCoordinates = glm::vec2(0.0f, 0.0f);

    Vertex vertex4;
    vertex4.position = glm::vec3(1.0f, -1.0f, 0.0f);
   // vertex4.normal = glm::vec3(1.0f, 0.0f, 1.0f);
    vertex4.textureCoordinates = glm::vec2(0.0f, textureCoordMultiplier);

    vertices.push_back(vertex1);
    vertices.push_back(vertex2);
    vertices.push_back(vertex3);
    vertices.push_back(vertex4);

    GLuint indices[] = {
      0, 1, 2,
      0, 2, 3,
    };

    Texture texture;
    texture.imagePath = imagePath;

    mesh->vertices = vertices; 
    mesh->indices.assign(indices, indices + 6);
    mesh->texture = texture;
    
    return mesh;
  }
};