#ifndef TEXTURE_HH
#define TEXTURE_HH

#include <iostream>
#include <vector>
#include <fstream>
#include <GL/glut.h>

typedef unsigned int TextureID;

struct Bitmap{
    unsigned char * data;
    int w, h;

    void loadBMP(const char * filename){
        FILE* f = fopen(filename, "rb");
        unsigned char info[54];
        fread(info, sizeof(unsigned char), 54, f);

        int width = *(int*)&info[18];
        int height = *(int*)&info[22];

        int size = 3 * width * height;
        this->w = width;
        this->h = height;
        fread(this->data, sizeof(unsigned char), size, f);
        fclose(f);

        for(int i = 0; i < size; i += 3)
        {
            unsigned char tmp = this->data[i];
            this->data[i] = this->data[i+2];
            this->data[i+2] = tmp;
        }
    }
};

void LoadTexture(TextureID, const char *);

#endif