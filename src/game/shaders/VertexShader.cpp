#include"VertexShader.h"
#include"Shader.h"

VertexShader::VertexShader(const char* fileName) {
     id = glCreateShader(GL_VERTEX_SHADER);
    std::string shaderFile = Shader::loadShaderSrc(fileName);
    const GLchar* Shadersrc = shaderFile.c_str();
    glShaderSource(id, 1, &Shadersrc, NULL);
    glCompileShader(id);
    int  success;
    char infoLog[512];
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        std::cout << "ERROR !!! SHADER::" << fileName << "::COMPILATION_FAILED\n" << infoLog << std::endl;
    }else  std::cout << "VERTEX SHADER::" << fileName << "::COMPILATION_SUCCESSED\n"  << std::endl;   
}
VertexShader::~VertexShader() {
    glDeleteShader(id);
}