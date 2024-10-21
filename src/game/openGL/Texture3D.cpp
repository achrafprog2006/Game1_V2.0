#include"Texture3D.h"

Texture3D::Texture3D(DataTexture** textures) {
   //right left top bottom back front
    glGenTextures(1,&id);
    use();
    for (int i = 0; i < 6; i++) {
        glTexImage2D(
            GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
            0, GL_RGB, textures[i]->width, textures[i]->height, 0, GL_RGB, GL_UNSIGNED_BYTE, textures[i]->data
        );
        delete textures[i];
    }
    delete[] textures;
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

    void Texture3D::use(){
        glBindTexture(GL_TEXTURE_CUBE_MAP,id);
    }
    void Texture3D::activateOn(int unit) {
        glActiveTexture(GL_TEXTURE0 + unit);
        use();
    }
    Texture3D::~Texture3D() {
        glDeleteTextures(1, &id);
    }


