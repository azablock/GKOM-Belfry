#pragma once

#include <SOIL.h>
#include <GL/glew.h>
#include "Texture.h"

class TextureLoader {

public:
  static void load(Texture& texture) {
    int width;
    int height;
    unsigned char* image = SOIL_load_image(texture.imagePath.c_str(), &width, &height, 0, SOIL_LOAD_RGB);

    if (image == nullptr)
      throw std::exception("Failed to load texture file");

    glGenTextures(1, &texture.id);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture.id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
  }
};