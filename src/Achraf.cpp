
#include "headers/Achraf.h"

float Achraf::a = 1;
long long Achraf::getCurrentTimeMillis(){
    time_t currentTime = time(NULL);
    clock_t currentTicks = clock();
    long long milliseconds = (long long)currentTime * 1000LL + (long long)(currentTicks * 1000 / CLOCKS_PER_SEC);
    return milliseconds;
}
float Achraf::randa() {
    float randomValue = (float)std::rand() / RAND_MAX;
    return randomValue;
}
float Achraf::rand(float start, float end) {
    return  start+Achraf::randa()*(end-start);
}
void Achraf::printOpenGLinfo() {
    // Print OpenGL version
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    // Print GPU renderer
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

    // Print GPU vendor
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;

    // Print supported extensions
    const GLubyte* extensions = glGetString(GL_EXTENSIONS);
    if (extensions) {
        std::cout << "Supported Extensions:" << std::endl;
        std::cout << reinterpret_cast<const char*>(extensions) << std::endl;
    }
    else {
        std::cerr << "Failed to retrieve extensions information!" << std::endl;
    }

    // Print shader version
    std::cout << "Shader Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    // Print OpenGL context flags
    GLint contextFlags;
    glGetIntegerv(GL_CONTEXT_FLAGS, &contextFlags);
    std::cout << "OpenGL Context Flags: " << std::hex << contextFlags << std::dec << std::endl;

    // Print available OpenGL extensions
    GLint numExtensions;
    glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);
    std::cout << "Number of Available Extensions: " << numExtensions << std::endl;

    // Print the number of texture units
    GLint maxTextureUnits;
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxTextureUnits);
    std::cout << "Max Texture Units: " << maxTextureUnits << std::endl;

    // Print the maximum texture size
    GLint maxTextureSize;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTextureSize);
    std::cout << "Max Texture Size: " << maxTextureSize << std::endl;

    // Print the maximum viewport dimensions
    GLint maxViewportDims[2];
    glGetIntegerv(GL_MAX_VIEWPORT_DIMS, maxViewportDims);
    std::cout << "Max Viewport Dimensions: " << maxViewportDims[0] << " x " << maxViewportDims[1] << std::endl;

}
void Achraf::write(unsigned char * data) {
    /*unsigned char data[] = {
           255, 0, 0, 255,   // Pixel (0, 0): RGBA(255, 0, 0, 255)   // Red
           0, 255, 0, 255,   // Pixel (1, 0): RGBA(0, 255, 0, 255)   // Green
           0, 0, 255, 255,   // Pixel (0, 1): RGBA(0, 0, 255, 255)   // Blue
           255, 255, 0, 255  // Pixel (1, 1): RGBA(255, 255, 0, 255) // Yellow
    };

    int width = 2;
    int height = 2;
    int channels = 4; // Assuming RGBA data

    // Encode the data array to a PNG file
    if (stbi_write_png("output.png", width, height, channels, data, width * channels) != 0) {
        std::cout << "Image successfully saved to output.png" << std::endl;
    }
    else {
        std::cerr << "Failed to save image" << std::endl;
    }*/
}
