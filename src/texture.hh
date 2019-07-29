#ifndef TEXTURE_HH
#define TEXTURE_HH

#include <iostream>
#include <GL/glut.h>

typedef unsigned int TextureID;

class Texture {
    private:
        TextureID texID;
        std::string filename;
        int width, height;

    public:
        Texture();
        Texture(const char *);
        Texture(const char *, int, int);

        bool IsLoaded();
        void LoadTexture();
        TextureID GetTexture();
};


#endif