#ifndef KEYBOARD_HH
#define KEYBOARD_HH

enum Keys
{
    W = 0,
    A = 1,
    S = 2,
    D = 3,
    LCTRL = 4,
    LSHIFT = 5,
    SPACE = 6
};

struct KeyPair
{
    Keys key;
    bool state;

    KeyPair(Keys k): key(k), state(false) {};
    KeyPair(Keys k, bool s): key(k), state(s) {};


    void
    PressKey(KeyPair * keyPair)
    {
        keyPair->state = true;
    }

    void
    ReleaseKey(KeyPair * keyPair)
    {
        keyPair->state = false;
    }

    void
    ToggleKey(KeyPair * keyPair)
    {
        keyPair->state = !keyPair->state;
    }
};

struct ControlKey
{
    KeyPair w;
    KeyPair a;
    KeyPair s;
    KeyPair d;
    KeyPair lctrl;
    KeyPair lshift;
    KeyPair space;
}

#endif // keyboard.hh
