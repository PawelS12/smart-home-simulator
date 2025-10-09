// 'sh' namespace - random & PI

#pragma once

#include <random>

namespace sh {
    inline constexpr double PI = 3.14159265358979323846;
    
    inline std::random_device rd;
    inline std::mt19937 gen{rd()};

    inline int randomInt(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen);
    }

    inline float randomFloat(float min, float max) {
        std::uniform_real_distribution<float> dist(min, max);
        return dist(gen);
    }
}