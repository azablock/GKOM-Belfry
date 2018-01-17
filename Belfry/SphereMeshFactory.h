#pragma once

#include <glm\glm.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include "MeshFactory.h"

class SphereMeshFactory : public MeshFactory {
public:

  Mesh* newInstance(std::string imagePath) {
    auto mesh = new Mesh();
   
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

    glm::vec4 blue = glm::vec4(0, 0, 1, 1);

    int n = 1;
    unsigned int rings = 24 * n;
    unsigned int sectors = 48 * n;

    float const R = 1.0f / (float)(rings - 1);
    float const S = 1.0f / (float)(sectors - 1);

    float pi = 3.14159265358979323846f;

    for (unsigned int r = 0; r < rings; r++) {
      for (unsigned int s = 0; s < sectors; s++) {

        float const y = sin(-pi / 2.0f + pi * r * R);
        float const x = cos(2 * pi * s * S) * sin(pi * r * R);
        float const z = sin(2 * pi * s * S) * sin(pi * r * R);

        glm::vec2 texCoord = glm::vec2(s*S, r*R);
        glm::vec3 vxs = glm::vec3(x, y, z);

        Vertex vertex;
        vertex.position = vxs;
        vertex.textureCoordinates = texCoord;

        vertices.push_back(vertex);
      }
    }

    indices.resize(rings * sectors * 6);
    std::vector<GLuint>::iterator i = indices.begin();

    for (unsigned int r = 0; r < rings - 1; r++) {
      for (unsigned int s = 0; s < sectors - 1; s++) {
        *i++ = r * sectors + s;
        *i++ = r * sectors + (s + 1);
        *i++ = (r + 1) * sectors + (s + 1);

        *i++ = (r + 1) * sectors + (s + 1);
        *i++ = (r + 1) * sectors + s;
        *i++ = r * sectors + s;
      }
    }

    mesh->vertices = vertices;
    mesh->indices = indices;

    Texture texture;
    texture.imagePath = imagePath;

    mesh->texture = texture;

    return mesh;
  }
};