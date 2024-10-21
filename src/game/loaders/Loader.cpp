#include"Loader.h"
Loader::Loader(){}

struct Vertex {
    float x, y, z;
};

struct TextureCoordinate {
    float u, v;
};

struct Normal {
    float nx, ny, nz;
};

DataPack* Loader::loadAchrafFile(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return nullptr;
    }
    
        DataPack* data = new DataPack();
        std::string line;
        std::getline(file, line);
        std::istringstream issV(line);
        int size, t;
        issV >> size;
        data->verticesSize = size;
        float* vertices = new float[size * 3];
        for (int i = 0; i < size; i++) {
            std::getline(file, line);
            std::istringstream issv(line);
            issv >> vertices[3 * i] >> vertices[3 * i + 1] >> vertices[3 * i + 2];
        }
       
        std::getline(file, line);
        std::istringstream issT(line);
        issT >> size;
        data->texCoordsSize = size;
        float* textureCoords = new float[size * 2];
        for (int i = 0; i < size; i++) {
            std::getline(file, line);
            std::istringstream isst(line);
            isst >> textureCoords[2 * i] >> textureCoords[2 * i + 1];

        }
        std::getline(file, line);
        std::istringstream issN(line);
        issN >> size;
        data->normalsSize = size;
        float* normals = new float[size * 3];
        for (int i = 0; i < size; i++) {
            std::getline(file, line);
            std::istringstream issn(line);
            issn >> normals[3 * i] >> normals[3 * i + 1] >> normals[3 * i + 2];
        }
        std::getline(file, line);
        std::istringstream issI(line);
        issI >> size;
        data->indicesSize = size*3;
        unsigned int* indices = new unsigned int[size * 3];
        for (int i = 0; i < size; i++) {
            std::getline(file, line);
            std::istringstream issi(line);
            issi >> indices[3 * i] >> indices[3 * i + 1] >> indices[3 * i + 2];
        }
        data->vertices = vertices;
        data->texCoords = textureCoords;
        data->normals = normals;
        data->indices = indices;

        return data;
}
float height(int i, int j, int size, DataTexture* tex) {
    return tex->getValue((i) * 1. / size, (j) * 1. / size) ;
}
void normalise(float* x) {
    float magnitude = sqrt(pow(x[0], 2) + pow(x[1], 2) + pow(x[2], 2));
    if (magnitude != 0)
     x[0] /= magnitude;
     x[1] /= magnitude;
     x[2] /= magnitude;
}

Mesh* Loader::generateTerrain(int size ,int unit , const char* heightMap,float maxHeight) {
    DataTexture* tex = new DataTexture(heightMap);
        DataPack* data = new DataPack();
        data->verticesSize = 4 * size * size;
        data->indicesSize = 6 * size * size;
        float* vertices = new float[data->verticesSize * 3];
        float* normals = new float[data->verticesSize * 3];
        float* texCoords = new float[data->verticesSize * 2];
        unsigned int* indices = new unsigned int[data->indicesSize];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int cst = (i * 12 * size) + (j * 12);
                if (i == 0) {
                    std::cout << (j) * 1. / size <<"//" << 1 - ((i) * 1. / size)<<" rgb : " << tex->getValue((j) * 1. / size, 1 - ((i) * 1. / size))<< std::endl;
                }
                vertices[cst + 0] =-j;
                vertices[cst + 1] = (tex->getValue((j) * 1. / size, 1 - ((i) * 1. / size))-127) /127*maxHeight;
                vertices[cst + 2] =i;

                vertices[cst + 3] = -j;
                vertices[cst + 4] =(tex->getValue( (j) * 1. /size , 1-((i+1) * 1. /size)) -127) / 127 * maxHeight;
                vertices[cst + 5] = i+1;

                vertices[cst + 6] = -j-1;
                vertices[cst + 7] =  (tex->getValue( (j+1) * 1. /size , 1-((i+1) * 1. /size)  )-127) / 127 * maxHeight;
                vertices[cst + 8] = i+1;

                vertices[cst + 9] = -j-1;
                vertices[cst + 10] =  (tex->getValue((j + 1)*1. / size, 1 - ((i) * 1. / size))-127) / 127 * maxHeight;
                vertices[cst + 11] = i;
                

                //normal1
                normals[cst + 0] = tex->getValue( (j-1) * 1. /size , 1-(i * 1. /size)) - tex->getValue((j +1) * 1. / size, 1 - (i * 1. / size));
                normals[cst + 1] = 2.0f;
                normals[cst + 2] = tex->getValue((j) * 1. / size, 1 - ((i-1) * 1. / size)) - tex->getValue((j) * 1. / size, 1 - ((i+1) * 1. / size));
                normalise(&normals[cst+0]);

                //normal2 
                //x-1,j  - x+1,j
                //x,j-1  - x,j+1
                normals[cst + 3] = tex->getValue((j-1) * 1. / size, 1 - ((i + 1) * 1. / size)) - tex->getValue((j +1) * 1. / size, 1 - ((i + 1) * 1. / size));
                normals[cst + 4] = 2.0f;
                normals[cst + 5] = tex->getValue((j) * 1. / size, 1 - ((i) * 1./ size)) - tex->getValue((j) * 1. / size, 1 - ((i + 2) * 1. / size));
                normalise(&normals[cst + 3]);
                //normal3
                normals[cst + 6] = tex->getValue((j) * 1. / size, 1 - ((i + 1) * 1. / size)) - tex->getValue((j + 2) * 1. / size, 1 - ((i + 1) * 1. / size));
                normals[cst + 7] = 2.0f;
                normals[cst + 8] = tex->getValue((j + 1) * 1. / size, 1 - ((i) * 1. / size)) - tex->getValue((j + 1) * 1. / size, 1 - ((i + 2) * 1. / size));
                normalise(&normals[cst + 6]);
                //normal4
                normals[cst + 9] = tex->getValue((j) * 1. / size, 1 - ((i) * 1. / size)) - tex->getValue((j + 2) * 1. / size, 1 - ((i) * 1. / size));
                normals[cst + 10] = 2.0f;
                normals[cst + 11] = tex->getValue((j + 1) * 1. / size, 1 - ((i-1) * 1. / size)) - tex->getValue((j + 1) * 1. / size, 1 - ((i+1) * 1. / size));
                normalise(&normals[cst + 9]);


                texCoords[(i * 8 * size) + (j * 8) + 0] = 0;
                texCoords[(i * 8 * size) + (j * 8) + 1] = 0;
                texCoords[(i * 8 * size) + (j * 8) + 2] = 0;
                texCoords[(i * 8 * size) + (j * 8) + 3] = 1;
                texCoords[(i * 8 * size) + (j * 8) + 4] = 1;
                texCoords[(i * 8 * size) + (j * 8) + 5] = 1;
                texCoords[(i * 8 * size) + (j * 8) + 6] = 1;
                texCoords[(i * 8 * size) + (j * 8) + 7] = 0;

                indices[(i * 6 * size) + (j * 6) + 0] = (i * 4 * size) + (4 * j) + 0;
                indices[(i * 6 * size) + (j * 6) + 1] = (i * 4 * size) + (4 * j) + 1;
                indices[(i * 6 * size) + (j * 6) + 2] = (i * 4 * size) + (4 * j) + 2;
                indices[(i * 6 * size) + (j * 6) + 3] = (i * 4 * size) + (4 * j) + 2;
                indices[(i * 6 * size) + (j * 6) + 4] = (i * 4 * size) + (4 * j) + 3;
                indices[(i * 6 * size) + (j * 6) + 5] = (i * 4 * size) + (4 * j) + 0;

            }
        }
        data->vertices = vertices;
        data->texCoords = texCoords;
        data->normals = normals;
        data->indices = indices;
        delete tex;
        return new Mesh(data);
}

Mesh* Loader::generateTerrain2(int size, int unit, const char* heightMap, float maxHeight) {
    DataTexture* tex = new DataTexture(heightMap);
    DataPack* data = new DataPack();
    data->verticesSize = 4 * size * size;
    data->indicesSize = 6 * size * size;
    float* vertices = new float[data->verticesSize * 3];
    float* normals = new float[data->verticesSize * 3];
    float* texCoords = new float[data->verticesSize * 2];
    unsigned int* indices = new unsigned int[data->indicesSize];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int cst = (i * 12 * size) + (j * 12);
            vertices[cst + 0] = (i - size / 2) * unit;
            vertices[cst + 1] = (tex->getValue((size - i) * 1. / size, j * 1. / size) - 127) / 128 * maxHeight;
            vertices[cst + 2] = (j - size / 2) * unit;
            vertices[cst + 3] = (i + 1 - size / 2) * unit;
            vertices[cst + 4] = (tex->getValue((size - (i + 1)) * 1. / size, j * 1. / size) - 127) / 128 * maxHeight;
            vertices[cst + 5] = (j - size / 2) * unit;
            vertices[cst + 6] = (i + 1 - size / 2) * unit;
            vertices[cst + 7] = (tex->getValue((size - (i + 1)) * 1. / size, (j + 1) * 1. / size) - 127) / 128 * maxHeight;
            vertices[cst + 8] = (j + 1 - size / 2) * unit;
            vertices[cst + 9] = (i - size / 2) * unit;
            vertices[cst + 10] = (tex->getValue((size - i) * 1. / size, (j + 1) * 1. / size) - 127) / 128 * maxHeight;
            vertices[cst + 11] = (j + 1 - size / 2) * unit;


            //normal1
            normals[cst + 0] = ((tex->getValue((size - (i - 1)) * 1. / size, (j) * 1. / size) - 127) / 128 * maxHeight) - vertices[cst + 4];
            normals[cst + 1] = 2.0f;
            normals[cst + 2] = ((tex->getValue((size - (i)) * 1. / size, (j - 1) * 1. / size) - 127) / 128 * maxHeight) - vertices[cst + 10];
            normalise(&normals[cst + 0]);

            //normal2 
            //x-1,j  - x+1,j
            //x,j-1  - x,j+1
            normals[cst + 3] = vertices[cst + 1] - (tex->getValue((size - (i + 2)) * 1. / size, j * 1. / size) - 127) / 128 * maxHeight;
            normals[cst + 4] = 2.0f;
            normals[cst + 5] = (tex->getValue((size - (i + 1)) * 1. / size, (j - 1) * 1. / size) - 127) / 128 * maxHeight - vertices[cst + 7];
            normalise(&normals[cst + 3]);
            //normal3
            normals[cst + 6] = vertices[cst + 10] - (tex->getValue((size - (i + 2)) * 1. / size, (j + 1) * 1. / size) - 127) / 128 * maxHeight;
            normals[cst + 7] = 2.0f;
            normals[cst + 8] = vertices[cst + 4] - (tex->getValue((size - (i + 1)) * 1. / size, (j + 2) * 1. / size) - 127) / 128 * maxHeight;
            normalise(&normals[cst + 6]);
            //normal4
            normals[cst + 9] = (tex->getValue((size - (i - 1)) * 1. / size, (j + 1) * 1. / size) - 127) / 128 * maxHeight - vertices[cst + 7];
            normals[cst + 10] = 2.0f;
            normals[cst + 11] = vertices[cst + 1] - (tex->getValue((size - i) * 1. / size, (j + 2) * 1. / size) - 127) / 128 * maxHeight;
            normalise(&normals[cst + 9]);


            texCoords[(i * 8 * size) + (j * 8) + 0] = 0;
            texCoords[(i * 8 * size) + (j * 8) + 1] = 1;
            texCoords[(i * 8 * size) + (j * 8) + 2] = 1;
            texCoords[(i * 8 * size) + (j * 8) + 3] = 1;
            texCoords[(i * 8 * size) + (j * 8) + 4] = 1;
            texCoords[(i * 8 * size) + (j * 8) + 5] = 0;
            texCoords[(i * 8 * size) + (j * 8) + 6] = 0;
            texCoords[(i * 8 * size) + (j * 8) + 7] = 0;

            indices[(i * 6 * size) + (j * 6) + 0] = (i * 4 * size) + (4 * j) + 0;
            indices[(i * 6 * size) + (j * 6) + 1] = (i * 4 * size) + (4 * j) + 1;
            indices[(i * 6 * size) + (j * 6) + 2] = (i * 4 * size) + (4 * j) + 2;
            indices[(i * 6 * size) + (j * 6) + 3] = (i * 4 * size) + (4 * j) + 2;
            indices[(i * 6 * size) + (j * 6) + 4] = (i * 4 * size) + (4 * j) + 3;
            indices[(i * 6 * size) + (j * 6) + 5] = (i * 4 * size) + (4 * j) + 0;

        }
    }
    data->vertices = vertices;
    data->texCoords = texCoords;
    data->normals = normals;
    data->indices = indices;
    delete tex;
    return new Mesh(data);
}


