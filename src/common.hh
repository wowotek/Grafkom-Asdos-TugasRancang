#ifndef COMMON_HH
#define COMMON_HH

#define up3(vec3) \
    vec3.x, vec3.y, vec3.z
#define up3add(vec3, ax, ay, az) \
    vec3.x + ax, vec3.y + ay, vec3.z + az
#define up2(vec2) \
    vec2.x, vec2.y


template <typename T>
struct Vec3{
    T x, y, z;

    Vec3() = default;
    Vec3(T ix, T iy, T iz) : x(ix), y(iy), z(iz) {}
    Vec3(T s): x(s), y(s), z(s) {};
};

typedef Vec3<float> Vec3f;
typedef Vec3<float> Color3f;
typedef Vec3<float> Coord3D;


template <typename T>
struct Vec2{
    T x, y;

    Vec2() = default;
    Vec2(T ix, T iy): x(ix), y(iy) {};
    Vec2(T s): x(s), y(s) {};
};

typedef Vec2<float> Vec2f;
typedef Vec2<float> Coord2D;

#endif