#include "keyboard.hh"

#include <GL/glut.h>

struct Keyboard::Manager
{
    static const Keyboard* keyboard;
    static bool isStarted;

    Manager (const Keyboard* keyboard);

    static void start (void);

    void static handleKeyDown (GLubyte charCode, int, int);
    void static handleKeyUp (GLubyte charCode, int, int);
    void static handleSpecialKeyDown (int key, int, int);
    void static handleSpecialKeyUp (int key, int, int);
};

static void Keyboard::Manager::handleKeyDown (GLubyte charCode, int, int)
{
    if (charCode == 'w' || charCode == 'W')
        keyboard->setKeyPressed(Keyboard::Key::W, true);
    else if(charCode == 'a' || charCode == 'A')
        keyboard->setKeyPressed(Keyboard::Key::A, true);
    else if(charCode == 's' || charCode == 'S')
        keyboard->setKeyPressed(Keyboard::Key::S, true);
    else if(charCode == 'd' || charCode == 'D')
        keyboard->setKeyPressed(Keyboard::Key::D, true);
}

Keyboard::Manager::Manager (const Keyboard* keyboard)
{
    this->keyboard = keyboard;
}

static void Keyboard::Manager::start (void)
{
    glutKeyboardFunc(handleKeyDown);
    glutKeyboardUpFunc(handleKeyUp);
    glutSpecialFunc(handleSpecialKeyDown);
    glutSpecialUpFunc(handleSpecialKeyUp);
    Keyboard::Manager::isStarted = true;
}

Keyboard::Keyboard (void): manager(new Manager(this))
{
    if (!Manager::isStarted)
    {
        Manager::start();
    }

    this->pressedKeys = Keymap();
    this->toggledKeys = Keymap();
}

Keyboard::~Keyboard (void)
{
}

void Keyboard::toggleKey (Key k)
{
    bool* p = &this->toggledKeys[k];
    *p = !(*p);
}

void Keyboard::setKeyPressed (Key k, bool b)
{
    bool *p = &this->pressedKeys[k];
    if ( *p != b )
    {
        this->toggleKey(k);
        *p = b;
    }
}

bool Keyboard::getKeyPressed (Key k) const
{
    return this->pressedKeys.at(k);
}

bool Keyboard::getKeyToggled (Key k) const
{
    return this->toggledKeys.at(k);
}