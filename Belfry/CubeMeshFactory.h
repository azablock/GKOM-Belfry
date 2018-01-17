#pragma once

#include "MeshFactory.h"

class CubeMeshFactory : public MeshFactory {
public:
  Mesh* newInstance(std::string imagePath) {
    auto mesh = new Mesh();

    GLfloat halfSideLength = 0.5f;
    GLfloat textureCoord = 1.0f;

    /*
    //std::vector<glm::vec3> geometryVertices = {
    //  //front
    //  glm::vec3(-0.5f, 0.5f, 0.5f),   //top left
    //  glm::vec3(0.5f, 0.5f, 0.5f),    //top right
    //  glm::vec3(0.5f, -0.5f, 0.5f),   //bottom right
    //  glm::vec3(-0.5f, -0.5f, 0.5f),  //bottom left

    //  //back
    //  glm::vec3(-0.5f, 0.5f, -0.5f),
    //  glm::vec3(0.5f, 0.5f, -0.5f),
    //  glm::vec3(0.5f, -0.5f, -0.5f),
    //  glm::vec3(-0.5f, -0.5f, -0.5f),

    //  //left
    //  glm::vec3(-0.5f, 0.5f, 0.5f),
    //  glm::vec3(-0.5f, 0.5f, -0.5f),
    //  glm::vec3(-0.5f, -0.5f, -0.5f),
    //  glm::vec3(-0.5f, -0.5f, 0.5f),

    //  //right
    //  glm::vec3(0.5f, 0.5f, 0.5f),
    //  glm::vec3(0.5f, 0.5f, -0.5f),
    //  glm::vec3(0.5f, -0.5f, -0.5f),
    //  glm::vec3(0.5f, -0.5f, 0.5f),

    //  //top
    //  glm::vec3(-0.5f, 0.5f, 0.5f),
    //  glm::vec3(-0.5f, 0.5f, -0.5f),
    //  glm::vec3(0.5f, 0.5f, -0.5f),
    //  glm::vec3(0.5f, 0.5f, 0.5f),

    //  //bottom
    //  glm::vec3(-0.5f, -0.5f, 0.5f),
    //  glm::vec3(-0.5f, -0.5f, -0.5f),
    //  glm::vec3(0.5f, -0.5f, -0.5f),
    //  glm::vec3(0.5f, -0.5f, 0.5f),
    //};

    //std::vector<Vertex> vertices;

    //for (std::vector<glm::vec3>::iterator it = geometryVertices.begin(); it != geometryVertices.end(); ++it) {
    //  Vertex vertex;
    //  vertex.position = *it;
    //  vertex.textureCoordinates = glm::vec2(0.0f, 1.0f);
    //  
    //  vertices.push_back(vertex);
    //}

    //GLuint indices[] = {
    //  // front
    //  0, 1, 2,
    //  2, 3, 0,
    //  // top
    //  1, 5, 6,
    //  6, 2, 1,
    //  // back
    //  7, 6, 5,
    //  5, 4, 7,
    //  // bottom
    //  4, 0, 3,
    //  3, 7, 4,
    //  // left
    //  4, 5, 1,
    //  1, 0, 4,
    //  // right
    //  3, 2, 6,
    //  6, 7, 3,
    //};
    */


    int textureMultiplier = 1;

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
};