#include"DataTexture.h"

DataTexture::DataTexture(const char* path) {
    data = stbi_load(path, &width, &height, &channels, STBI_rgb);
    std::cout << "loading the image \"" << path << "\" ...." << std::endl;
    if (!data) 
        std::cout << "Failed to load " << path << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "| width: " << width << "| height: " << height << "| channels:" << channels<<" |" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;

}


float DataTexture::getValue(float x,  float y) {

    if (y >= 1)y = 0.99;
    if (y <= 0)y = 0;
    if (x >= 1)x = 0.99;
    if (x <= 0)x = 0;


    int ind = ((int)(y * height) * width + (int)(x * width)) * 3;

    int r = (int)data[ind]
        , g = (int)data[ind + 1]
        , b = (int)data[ind + 2];
    return b;

}
DataTexture::~DataTexture() {
    stbi_image_free(data);
}