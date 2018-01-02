#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>

class Shader {

public:
  Shader(const GLchar* vertexPath, const GLchar* fragmentPath) {
    std::string vertex_code = readShaderCode(vertexPath);
    GLuint vertexId = compileShader(vertex_code.c_str(), GL_VERTEX_SHADER);

    std::string fragmentCode = readShaderCode(fragmentPath);
    GLuint fragmentId = compileShader(fragmentCode.c_str(), GL_FRAGMENT_SHADER);

    _id = glCreateProgram();
    glAttachShader(_id, vertexId);
    glAttachShader(_id, fragmentId);
    glLinkProgram(_id);

    GLint success;
    glGetProgramiv(_id, GL_LINK_STATUS, &success);
    
    if (!success) {
      GLchar infoLog[512];
      glGetProgramInfoLog(_id, sizeof(infoLog), NULL, infoLog);
      std::string msg = std::string("Shader program linking: ") + infoLog;
      throw std::exception(msg.c_str());
    }

    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);
  }

  void use() {
    glUseProgram(_id);
  }

  void setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(_id, name.c_str()), value);
  }

  GLuint id() const {
    return _id;
  }

private:
  GLuint _id;

  std::string readShaderCode(const GLchar* shaderPath) {
    std::ifstream shader_file;
    shader_file.exceptions(std::ifstream::badbit);

    shader_file.open(shaderPath);
    std::stringstream shader_stream;
    shader_stream << shader_file.rdbuf();
    shader_file.close();
    return shader_stream.str();
  }

  GLuint compileShader(const GLchar* shaderCode, GLenum shaderType) {
    GLuint shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId, 1, &shaderCode, NULL);
    glCompileShader(shaderId);

    GLint success = 0;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    
    if (!success) {
      GLchar infoLog[512];
      glGetShaderInfoLog(shaderId, sizeof(infoLog), NULL, infoLog);
      std::string msg = std::string("Shader compilation: ") + infoLog;
      throw std::exception(msg.c_str());
    }
    
    return shaderId;
  }
};