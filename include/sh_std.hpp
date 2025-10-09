// Aliases for selected std:: types/functions inside the 'sh' namespace

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <functional>
#include <sstream>
#include <fstream>
#include <cmath>
#include <algorithm>

namespace sh {
    using std::string;
    using std::vector;
    using std::map;
    using std::shared_ptr;
    using std::make_shared;
    using std::unique_ptr;
    using std::function;
    using std::ostringstream;
    using std::istringstream;
    using std::sin;

    using std::cin;
    using std::ios;
    using std::cout;
    using std::cerr;
    using std::endl;
    using std::to_string;
    using std::ifstream;
    using std::ofstream;

    using std::min;
    using std::max;

    using std::remove;
}