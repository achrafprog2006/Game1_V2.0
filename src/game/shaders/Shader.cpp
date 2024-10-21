#include "Shader.h"
#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>
#include <cstring>  // for strerror
#include <sys/stat.h> // for stat
#include <unistd.h> 

bool fileExists(const std::string& filename) {
    struct stat buffer;   
    return (stat(filename.c_str(), &buffer) == 0); // Return true if the file exists
}
   
    Shader::Shader(VertexShader* vertexShader, FragmentShader* fragmentShader) {
        ID = glCreateProgram();
        glAttachShader(ID, vertexShader->id);
        glAttachShader(ID, fragmentShader->id);
        glLinkProgram(ID);
        int  success;
        char infoLog[512];
        glGetProgramiv(ID, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(ID, 512, NULL, infoLog);
            std::cout << "ERROR::Program::" << "::LINK_FAILED\n" << infoLog << std::endl;
        }
    }

    GLuint Shader::location(std::string name) {
       return glGetUniformLocation(ID, name.c_str());
    }
    void Shader::activate() {
        glUseProgram(ID);
    }
    void Shader::setMat4(std::string name, glm::mat4 value) {
        glUniformMatrix4fv(location(name), 1, GL_FALSE, glm::value_ptr(value));
    }
    void Shader::setFloat(std::string name, float value) {
        glUniform1f(location(name), value);
    }
    void Shader::setInt(std::string name, int value) {
        glUniform1i(location(name), value);
    }
    void Shader::setVec3(std::string name, glm::vec3 value) {
        glUniform3f(location(name),value.x, value.y, value.z);
    }
    Shader::~Shader() {
        glDeleteProgram(ID);
    }
    std::string Shader::loadShaderSrc(const char* filename) {
        std::ifstream file(filename);
        std::stringstream buf;
        std::string ret = "";
        if (!fileExists(filename)) {
        std::cerr << "File does not exist: " << filename << std::endl;
        return ret;
    }
        if (file.is_open()) {
            buf << file.rdbuf();
            ret = buf.str();
        }
        else std::cout << "Could not open " << filename << "!!!!" << std::endl;
        file.close();
        return ret;
    }
