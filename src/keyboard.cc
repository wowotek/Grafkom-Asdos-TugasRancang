#include "keyboard.hh"

Keyboard::Keyboard (void)
{
    this->pressedKeys = Keymap();
    this->toggledKeys = Keymap();
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