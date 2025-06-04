// 'sh' namespace - random

#pragma once

#include <random>

namespace sh {
    inline std::random_device rd;
    inline std::mt19937 gen{rd()};
}