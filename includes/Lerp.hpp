#pragma once 
#include <cmath>

inline float lerp(float u , float v , float t)
{
    return std::fma(t, v - u, u); // u + t * (v - u)
}

template <typename V>
V lerp(V u , V v , float t)
{
    v.sub(u);
    v.scl(t);
    v.add(u);
    return v;
}