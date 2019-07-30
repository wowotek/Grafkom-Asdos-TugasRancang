#include "texture.hh"

Texture::Texture(const char * f, int w, int h){
    this->filename = std::string(f);
    this->width = w;
    this->height = h;
}

Texture::Texture(const char * f): Texture(f, 1024, 1024){}
Texture::Texture(): Texture("") {}

TextureID
Texture::GetTexture(){
    return this->texID;
}

bool
Texture::IsLoaded(){
    return (this->texID != 0);
}

void
Texture::LoadTexture(){
    if(this->IsLoaded()) {
        std::cerr << "File is Already Loaded !" << std::endl;
        return;
    }
    if(this->filename == "") {
        std::cerr << "Filename is not specified !" << std::endl;
        return;
    }

    unsigned char * data;

    FILE * file;

    file = fopen(this->filename.c_str(), "rb");
    data = (unsigned char *)malloc( this->width * this->height * 3 );

    fread(data, this->width * this->height * 3, 1, file);
    fclose(file);
    free(file);

    for(int i = 0; i < this->width * this->height; ++i){
        int index = i*3;
        unsigned char B, R;
        B = data[index];
        R = data[index+2];

        data[index] = R;
        data[index+2] = B;
    }

    glGenTextures(1, &this->texID);
    glBindTexture(GL_TEXTURE_2D, this->texID);
    glTexEnvf(
        GL_TEXTURE_ENV,
        GL_TEXTURE_ENV_MODE,
        GL_MODULATE
    );
    glTexParameterf(
        GL_TEXTURE_2D,
        GL_TEXTURE_MIN_FILTER,
        GL_LINEAR_MIPMAP_NEAREST
    );

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, this->width, this->height, GL_RGB, GL_UNSIGNED_BYTE, data );
    free(data);
};