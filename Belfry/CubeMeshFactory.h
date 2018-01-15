#pragma once

#include "MeshFactory.h"

class CubeMeshFactory : public MeshFactory {
public:
  Mesh* newInstance() {
    auto mesh = new Mesh();

    GLfloat halfSideLength = 0.5f;
    GLfloat textureCoord = 1.0f;

    std::vector<glm::vec3> geometryVertices = {
      //front
      glm::vec3(-0.5f, 0.5f, 0.5f),   //top left
      glm::vec3(0.5f, 0.5f, 0.5f),    //top right
      glm::vec3(0.5f, -0.5f, 0.5f),   //bottom right
      glm::vec3(-0.5f, -0.5f, 0.5f),  //bottom left

      //back
      glm::vec3(-0.5f, 0.5f, -0.5f),
      glm::vec3(0.5f, 0.5f, -0.5f),
      glm::vec3(0.5f, -0.5f, -0.5f),
      glm::vec3(-0.5f, -0.5f, -0.5f),

      //left
      glm::vec3(-0.5f, 0.5f, 0.5f),
      glm::vec3(-0.5f, 0.5f, -0.5f),
      glm::vec3(-0.5f, -0.5f, -0.5f),
      glm::vec3(-0.5f, -0.5f, 0.5f),

      //right
      glm::vec3(0.5f, 0.5f, 0.5f),
      glm::vec3(0.5f, 0.5f, -0.5f),
      glm::vec3(0.5f, -0.5f, -0.5f),
      glm::vec3(0.5f, -0.5f, 0.5f),

      //top
      glm::vec3(-0.5f, 0.5f, 0.5f),
      glm::vec3(-0.5f, 0.5f, -0.5f),
      glm::vec3(0.5f, 0.5f, -0.5f),
      glm::vec3(0.5f, 0.5f, 0.5f),

      //bottom
      glm::vec3(-0.5f, -0.5f, 0.5f),
      glm::vec3(-0.5f, -0.5f, -0.5f),
      glm::vec3(0.5f, -0.5f, -0.5f),
      glm::vec3(0.5f, -0.5f, 0.5f),
    };


    std::vector<Vertex> vertices;

    for (std::vector<glm::vec3>::iterator it = geometryVertices.begin(); it != geometryVertices.end(); ++it) {
      Vertex vertex;
      vertex.position = *it;
      vertex.textureCoordinates = glm::vec2(0.0f, 1.0f);
      
      vertices.push_back(vertex);
    }

    GLuint indices[] = {
      // front
      0, 1, 2,
      2, 3, 0,
      // top
      1, 5, 6,
      6, 2, 1,
      // back
      7, 6, 5,
      5, 4, 7,
      // bottom
      4, 0, 3,
      3, 7, 4,
      // left
      4, 5, 1,
      1, 0, 4,
      // right
      3, 2, 6,
      6, 7, 3,
    };

    Texture texture;
    texture.imagePath = "Stone1.png";

    mesh->vertices = vertices;
    mesh->indices.assign(indices, indices + 36); //todo sizeOf
    mesh->texture = texture;

    return mesh;
  }
};