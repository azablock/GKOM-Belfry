#pragma once

#include "MeshFactory.h"

class CylinderMeshFactory : public MeshFactory {
public:
  Mesh* newInstance() {
    auto mesh = new Mesh();

    glEnable(GL_CULL_FACE);

    int N = 20;
    int M = 20;

    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

    for (int i = 0; i <= N; ++i)
      for (int j = 0; j <= M; ++j)
      {
        float u = i / (float)N;
        float v = j / (float)M;





        vert[i + j*(N + 1)].p = getCylinderUV(u, v);
        vert[i + j*(N + 1)].c = glm::normalize(vert[i + j*(N + 1)].p);
      }


    for (int i = 0; i<N; ++i)
      for (int j = 0; j<M; ++j)
      {
        //      (i,j+1)
        //        o-----o(i+1,j+1)
        //        |\    |           a = p(u_i, v_i)
        //        | \   |           b = p(u_{i+1}, v_i)
        //        |  \  |           c = p(u_i, v_{i+1})
        //        |   \ |           d = p(u_{i+1}, v_{i+1})
        //        |    \|
        //  (i,j) o-----o(i+1, j)
        indices[6 * i + j * 3 * 2 * (N)+0] = (i)+(j)*  (N + 1);
        indices[6 * i + j * 3 * 2 * (N)+1] = (i + 1) + (j)*  (N + 1);
        indices[6 * i + j * 3 * 2 * (N)+2] = (i)+(j + 1)*(N + 1);
        indices[6 * i + j * 3 * 2 * (N)+3] = (i + 1) + (j)*  (N + 1);
        indices[6 * i + j * 3 * 2 * (N)+4] = (i + 1) + (j + 1)*(N + 1);
        indices[6 * i + j * 3 * 2 * (N)+5] = (i)+(j + 1)*(N + 1);
      }

    return mesh;
  }



  glm::vec3 getCylinderUV(float u, float v) {
    u *= -2 * 3.1415f;
    float r = 1;

    return glm::vec3(r * cosf(u), 2 * v, r * sinf(u));
  }
};