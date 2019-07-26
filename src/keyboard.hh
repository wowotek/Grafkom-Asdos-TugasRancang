#ifndef KEYBOARD_HH
#define KEYBOARD_HH

#include <map>

class Keyboard
{
    struct Impl;
    std::unique_ptr<Impl> p

    enum Key: uint32_t
    {
        W = 1,
        A = 2,
        S = 3,
        D = 4,
        SHIFT = 5,
        LEFT_CONTROL = 6
    };

    static const uint32_t MAX_KEY_COUNT = 16U;

    using Keymap = std::map<Key, bool>;
    Keymap pressedKeys, toggledKeys;

    void toggleKey (Key k);

    public:

    Keyboard (void);
    ~Keyboard (void);

    void setKeyPressed (Key k, bool b);
    bool getKeyPressed (Key k) const;

    bool getKeyToggled (Key k) const;
};

#endif