#ifndef COMMON_HH
#define COMMON_HH


// TOOLS
#define up3(vec3) \
    vec3.x, vec3.y, vec3.z

#define up3add(vec3, ax, ay, az) \
    vec3.x + ax, vec3.y + ay, vec3.z + az

#define up2(vec2) \
    vec2.x, vec2.y

#define mapRange(value, oldRangeMin, oldRangeMax, newRangeMin, newRangeMax) \
    ((((value - oldRangeMin) * (newRangeMax - newRangeMin)) / \
    (oldRangeMax - oldRangeMin)) + newRangeMin)

// Vectors
template <typename T>
struct Vec3
{
    T x, y, z;

    Vec3() = default;
    Vec3(T ix, T iy, T iz) : x(ix), y(iy), z(iz) {}
    Vec3(T s): x(s), y(s), z(s) {};
};

typedef Vec3<float> Vec3f;
typedef Vec3<float> Color3f;
typedef Vec3<float> Coord3D;


template <typename T>
struct Vec2
{
    T x, y;

    Vec2() = default;
    Vec2(T ix, T iy): x(ix), y(iy) {};
    Vec2(T s): x(s), y(s) {};
};

typedef Vec2<float> Vec2f;
typedef Vec2<float> Coord2D;

// Keyboards Related

enum Keys
{
    NONE = 0,
    W = 1,
    A = 2,
    S = 3,
    D = 4,
    LCTRL = 5,
    LSHIFT = 6,
    SPACE = 7
};

struct KeyPair
{
    Keys key;
    bool state;

    KeyPair(): key(NONE), state(false) {};
    KeyPair(Keys k): key(k), state(false) {};
    KeyPair(Keys k, bool s): key(k), state(s) {};

    void PressKey(){ this->state = true; }
    void ReleaseKey(){ this->state = false; }
    void ToggleKey(){ this->state = !this->state; }
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

    void ResetKeys(){
        w = KeyPair(W);
        a = KeyPair(A);
        s = KeyPair(S);
        d = KeyPair(D);
        lctrl  = KeyPair(LCTRL);
        lshift = KeyPair(LSHIFT);
        space  = KeyPair(SPACE);
    }

    bool IsCharKeyPressed(){
        if (w.state) return true;
        if (a.state) return true;
        if (s.state) return true;
        if (d.state) return true;
        return false;
    }

    bool IsSpecKeyPressed(){
        if (lctrl.state)  return true;
        if (lshift.state) return true;
        if (space.state)  return true;
        return false;
    }
};

// Mouse Related
struct MousePos{
    float pX, pY;
    float hX, hY;
    float cX, cY;

    void calculate(){
        hX = (pX - (glutGet(GLUT_WINDOW_WIDTH) / 2));
        hY = ((glutGet(GLUT_WINDOW_HEIGHT) / 2) - pY);

        cX = mapRange(hX, -800, 800, -0.1, 0.1);
        cY = mapRange(hY, -450, 450, -0.1, 0.1);
    }
    
    MousePos() = default;
    MousePos(float x): pX(x), pY(x) { calculate(); };
    MousePos(float x, float y): pX(x), pY(y) { calculate(); };
};

#endif