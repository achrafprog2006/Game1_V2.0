
#include "Texture.h"


Texture::Texture(const char* filename) {
   
    glGenTextures(1, &id);
    use();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
   // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    std::cout << "loading the image \"" << filename << "\" ...." << std::endl;
    int width, height, nChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(filename, &width, &height, &nChannels, 0);
    if (data) {
        if (nChannels == 3)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        else if (nChannels == 4)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        std::cout << "| width: " << width << "| height: " << height << "| channels:" << nChannels << " |" << std::endl;

    }
    else std::cout << "could not load the image" << std::endl;
    stbi_image_free(data);
}
void Texture::use() {
    glBindTexture(GL_TEXTURE_2D, id);
}
void Texture::activateOn(int unit) {
    glActiveTexture(GL_TEXTURE0 + unit);
    use();
}
Texture::~Texture() {
    glDeleteTextures(1, &id);
}