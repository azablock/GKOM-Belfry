#pragma once

#include <GL\glew.h>
#include <vector>
#include "Texture.h"
#include "Vertex.h"

class Mesh {
public:
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
  std::vector<Texture> textures;

  GLfloat* asVertexData() {
    std::vector<GLfloat> vertexData;

    for (int i = 0; i < vertices.size(); i++) {
      auto vertex = vertices[i];
      auto texture = textures[i];

      //coordinates
      vertexData.push_back(vertex.position.x);
      vertexData.push_back(vertex.position.y);
      vertexData.push_back(vertex.position.z);

      //color - ???
      vertexData.push_back(1.0f);
      vertexData.push_back(0.0f);
      vertexData.push_back(0.0f);

      //texture
      vertexData.push_back(vertex.textureCoordinates.x);
      vertexData.push_back(vertex.textureCoordinates.y);
    }

    return &vertexData[0];
  }
};