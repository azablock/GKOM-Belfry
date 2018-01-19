#pragma once

#include <glm\glm.hpp>
#include "MeshFactory.h"

class CylinderMeshFactory : public MeshFactory {
public:
  Mesh* newInstance(std::string imagePath) {
    auto mesh = new Mesh();

    int N = 20;
    int M = 20;

    std::vector<Vertex> vertices((N + 1)*(M + 1));
    std::vector<GLuint> indices(3 * 2 * (N)*(M));

    for (int i = 0; i < N + 1; i++)
      for (int j = 0; j < M + 1; j++) {
        float u = i / (float)N;
        float v = j / (float)M;
       
        GLfloat textureCoordS = (j / (GLfloat)(2 * glm::pi<float>()));
        GLfloat textureCoordT = j % 2 == 0 ? 0.0f : 1.0f;

        vertices[i + j*(N + 1)].position = getCylinderUV(u, v);
        vertices[i + j*(N + 1)].textureCoordinates = glm::vec2(textureCoordS, textureCoordT);
      }


    for (int i = 0; i<N; ++i)
      for (int j = 0; j<M; ++j) {
        indices[6 * i + j * 3 * 2 * (N)+0] = (i)+(j)*  (N + 1);
        indices[6 * i + j * 3 * 2 * (N)+1] = (i + 1) + (j)*  (N + 1);
        indices[6 * i + j * 3 * 2 * (N)+2] = (i)+(j + 1)*(N + 1);
        indices[6 * i + j * 3 * 2 * (N)+3] = (i + 1) + (j)*  (N + 1);
        indices[6 * i + j * 3 * 2 * (N)+4] = (i + 1) + (j + 1)*(N + 1);
        indices[6 * i + j * 3 * 2 * (N)+5] = (i)+(j + 1)*(N + 1);
      }

    Texture texture;
    texture.imagePath = imagePath;

    mesh->vertices = vertices;
    mesh->indices = indices;
    mesh->texture = texture;

    return mesh;
  }


private:
  glm::vec3 getCylinderUV(float u, float v) {
    u *= -2 * 3.1415f;
    float r = 1;

    return glm::vec3(r * cosf(u), 2 * v, r * sinf(u));
  }
};