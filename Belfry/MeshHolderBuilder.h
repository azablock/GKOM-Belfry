#pragma once

#include <vector>
#include "BlfComponentBuilder.h"
#include "MeshHolder.h"

class MeshHolderBuilder : public BlfComponentBuilder<MeshHolder> {

  MeshHolderBuilder* vertices(std::vector<glm::vec3> vertices) {
   /* std::vector<glm::vec3>::iterator it = vertices.begin();
    _instance->vertices.assign(it, vertices.end() - 1);
    return this;*/

    return NULL;
  }
};