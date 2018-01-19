#pragma once

#include "MeshFactory.h"

class CubeMeshFactory : public MeshFactory {
public:
  Mesh* newInstance(std::string imagePath) {
    auto mesh = new Mesh();

    GLfloat halfSideLength = 0.5f;
    GLfloat textureCoord = 1.0f;

    glm::vec2 firstVertexTextureCoordinate = glm::vec2(0, 0);
    glm::vec2 secondVertexTextureCoordinate = glm::vec2(textureMultiplier, 0);
    glm::vec2 thirdVertexTextureCoordinate = glm::vec2(textureMultiplier, textureMultiplier);
    glm::vec2 forthVertexTextureCoordinate = glm::vec2(0, textureMultiplier);

    std::vector<Vertex> vertices = {
      //front
      Vertex(glm::vec3(-1.0, -1.0, 1.0), firstVertexTextureCoordinate),
      Vertex(glm::vec3(1.0, -1.0, 1.0), secondVertexTextureCoordinate),
      Vertex(glm::vec3(1.0, 1.0, 1.0), thirdVertexTextureCoordinate),
      Vertex(glm::vec3(-1.0, 1.0, 1.0), forthVertexTextureCoordinate),

      //right
      Vertex(glm::vec3(1.0, 1.0, 1.0), firstVertexTextureCoordinate),
      Vertex(glm::vec3(1.0, 1.0, -1.0), secondVertexTextureCoordinate),
      Vertex(glm::vec3(1.0, -1.0, -1.0), thirdVertexTextureCoordinate),
      Vertex(glm::vec3(1.0, -1.0, 1.0), forthVertexTextureCoordinate),

      //back
      Vertex(glm::vec3(-1.0, -1.0, -1.0), firstVertexTextureCoordinate),
      Vertex(glm::vec3(1.0, -1.0, -1.0), secondVertexTextureCoordinate),
      Vertex(glm::vec3(1.0, 1.0, -1.0), thirdVertexTextureCoordinate),
      Vertex(glm::vec3(-1.0, 1.0, -1.0), forthVertexTextureCoordinate),

      //left
      Vertex(glm::vec3(-1.0, -1.0, -1.0), firstVertexTextureCoordinate),
      Vertex(glm::vec3(-1.0, -1.0, 1.0), secondVertexTextureCoordinate),
      Vertex(glm::vec3(-1.0, 1.0, 1.0), thirdVertexTextureCoordinate),
      Vertex(glm::vec3(-1.0, 1.0, -1.0), forthVertexTextureCoordinate),

      //top
      Vertex(glm::vec3(1.0, 1.0, 1.0), firstVertexTextureCoordinate),
      Vertex(glm::vec3(-1.0, 1.0, 1.0), secondVertexTextureCoordinate),
      Vertex(glm::vec3(-1.0, 1.0, -1.0), thirdVertexTextureCoordinate),
      Vertex(glm::vec3(1.0, 1.0, -1.0), forthVertexTextureCoordinate),

      //bottom
      Vertex(glm::vec3(-1.0, -1.0, -1.0), firstVertexTextureCoordinate),
      Vertex(glm::vec3(1.0, -1.0, -1.0), secondVertexTextureCoordinate),
      Vertex(glm::vec3(1.0, -1.0, 1.0), thirdVertexTextureCoordinate),
      Vertex(glm::vec3(-1.0, -1.0, 1.0), forthVertexTextureCoordinate),
    };

    std::vector<GLuint> indices = {
      0,  1,  2,  0,  2,  3,   //front
      4,  5,  6,  4,  6,  7,   //right
      8,  9,  10, 8,  10, 11 ,  //back
      12, 13, 14, 12, 14, 15,  //left
      16, 17, 18, 16, 18, 19,  //upper
      20, 21, 22, 20, 22, 23 }; //bottom

    Texture texture;
    texture.imagePath = imagePath;

    mesh->vertices = vertices;
    mesh->indices = indices;
    mesh->texture = texture;

    return mesh;
  }

  int textureMultiplier = 1;
};