#pragma once

#include "MeshFactory.h"

class CubeMeshFactory : public MeshFactory {
public:

  Mesh* newInstance() {
    auto mesh = new Mesh();
    
   // GLfloat vertices[] = {
			////position			      // color	    		// texture
			// 0.25f,  0.5f,  0.0f,	1.0f, 0.0f, 0.0f,	1.0f,  0.0f,	
			//-0.75f,  0.5f,  0.0f,	0.0f, 1.0f, 0.0f,	0.0f,  0.0f,
			//-0.25f, -0.5f,  0.0f,	0.0f, 0.0f, 1.0f,	0.0f,  1.0f,
			// 0.75f, -0.5f,  0.0f,	1.0f, 0.0f, 1.0f,	1.0f,  1.0f
   // };

    std::vector<Vertex> vertices;
    
    Vertex vertex1;
    vertex1.position = glm::vec3(0.25f, 0.5f, 0.0f);
    vertex1.normal = glm::vec3(1.0f, 0.0f, 0.0f);
    vertex1.textureCoordinates = glm::vec2(1.0f, 0.0f);

    Vertex vertex2;
    vertex2.position = glm::vec3(-0.75f, 0.5f, 0.0f);
    vertex2.normal = glm::vec3(0.0f, 1.0f, 0.0f);
    vertex2.textureCoordinates = glm::vec2(0.0f, 0.0f);

    Vertex vertex3;
    vertex3.position = glm::vec3(-0.25f, -0.5f, 0.0f);
    vertex3.normal = glm::vec3(0.0f, 0.0f, 1.0f);
    vertex3.textureCoordinates = glm::vec2(0.0f, 1.0f);

    Vertex vertex4;
    vertex4.position = glm::vec3(0.75f, -0.5f, 0.0f);
    vertex4.normal = glm::vec3(1.0f, 0.0f, 1.0f);
    vertex4.textureCoordinates = glm::vec2(1.0f, 1.0f);

    vertices.push_back(vertex1);
    vertices.push_back(vertex2);
    vertices.push_back(vertex3);
    vertices.push_back(vertex4);

    GLuint indices[] = {
      0, 1, 2,
      0, 2, 3,
    };

    mesh->vertices = vertices; 
    mesh->indices.assign(indices, indices + 6);
    
    return mesh;
  }
};