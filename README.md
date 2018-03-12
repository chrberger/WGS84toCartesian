## WGS84toCartesian - a simple header-only, single-file library to convert WGS84 positions (latitude/longitude) to/from Cartesian positions using Mercator projection for C++

[![Build Status](https://travis-ci.org/chrberger/WGS84toCartesian.svg?branch=master)](https://travis-ci.org/chrberger/WGS84toCartesian) [![Build status](https://ci.appveyor.com/api/projects/status/i3swddat4tlnxmm5?svg=true)](https://ci.appveyor.com/project/chrberger/WGS84toCartesian) [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

WGS84toCartesian is a small and efficient library written in modern C++ library to convert WGS84 latitude/longitude positions to/from Cartesian positions using Mercator projection.

WGS84toCartesian is available as single-file, header-only library - just drop [WGS84toCartesian.hpp](https://raw.githubusercontent.com/chrberger/WGS84toCartesian/master/WGS84toCartesian.hpp) into your project, `#include "WGS84toCartesian.hpp"`, and compile your project with a modern C++ compiler (C++11 or newer).

This library is partially based on the work from Gerald I. Evenden on proj 4.3 released under public domain terms. See thirdparty/proj-4.3 for further details.


## Table of Contents
* [Features](#features)
* [Dependencies](#dependencies)
* [Contributing](#contributing)
* [License](#license)


## Features
* Written in highly portable and high quality C++11
* **Available as header-only, single-file distribution - just drop [WGS84toCartesian.hpp](https://raw.githubusercontent.com/chrberger/WGS84toCartesian/master/WGS84toCartesian.hpp) into your project, `#include "WGS84toCartesian.hpp"`, and compile your project with a modern C++ compiler (C++11 or newer)**
* The positions are passed to and returned from the functions as [`std::array`](http://en.cppreference.com/w/cpp/container/array) so that this library integrates well with other math libraries (e.g., Eigen).
* Convert a given WGS84 position to a Cartesian position using a given WGS84 reference position with Mercator projection: `std::array<double, 2> cartesianPosition = wgs84::toCartesian({52.247041, 10.575830} /* reference position */, {52.248091, 10.57417} /* position to be converted */));`
* Convert a given WGS84 position to a Cartesian position using a given WGS84 reference position with Mercator projection: [Another example](https://github.com/chrberger/WGS84toCartesian/blob/master/test/Test-WGS84toCartesian.cpp#L40-L49)
* Approximate a given Cartesian position with a WGS84 position using a given WGS84 reference position with Mercator projection: `std::array<double, 2> approximatedWGS84Position = wgs84::fromCartesian({52.247041, 10.575830} /* reference position */, {-154.48, 441.75} /* position to be converted */);`
* Approximate a given Cartesian position with a WGS84 position using a given WGS84 reference position with Mercator projection: [Another example](https://github.com/chrberger/WGS84toCartesian/blob/master/test/Test-WGS84toCartesian.cpp#L82-L91)


## Dependencies
No dependencies! All you need is a C++11-compliant compiler (we are testing with GCC 6.3.0 and MSVC 19.0.24215.1) as the project ships the following dependencies as part of the source distribution:

* [Unit Test Framework Catch2](https://github.com/catchorg/Catch2/releases/tag/v2.1.1) - [![License: Boost Software License v1.0](https://img.shields.io/badge/License-Boost%20v1-blue.svg)](http://www.boost.org/LICENSE_1_0.txt) - [Source](https://github.com/chrberger/stringtoolbox/blob/master/test/catch.hpp)


## Installation
### Installation as single-file, header-only library
WGS84toCartesian is provided as header-only, single-file library as well - just drop [WGS84toCartesian.hpp](https://raw.githubusercontent.com/chrberger/WGS84toCartesian/master/WGS84toCartesian.hpp) into your project, `#include "WGS84toCartesian.hpp"`, and compile your project with a modern C++ compiler (C++11 or newer)


## Projects using WGS84toCartesian
If your project is using WGS84toCartesian, just let us know :-)


## Contributing
We are happy to receive your PRs to accelerate libcluon's development; before contributing, please take a look at the [Contribution Documents](CONTRIBUTING.md).


## License
* This project is released under the terms of the MIT License - [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

