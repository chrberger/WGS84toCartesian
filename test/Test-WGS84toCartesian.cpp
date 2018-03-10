/*
 * MIT License
 *
 * Copyright (c) 2018  Christian Berger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "WGS84toCartesian.hpp"

TEST_CASE("From WGS84 to Cartesian: Identical WGS84 position") {
    constexpr std::array<double, 2> WGS84Reference{52.247041, 10.575830};
    constexpr std::array<double, 2> expectedResult{0.0, 0.0};

    std::array<double, 2> result{wgs84::toCartesian(WGS84Reference, WGS84Reference)};

    REQUIRE(expectedResult[0] == Approx(result[0]));
    REQUIRE(expectedResult[1] == Approx(result[1]));
}

TEST_CASE("From WGS84 to Cartesian: First example") {
    constexpr std::array<double, 2> WGS84Reference{52.247041, 10.575830};
    constexpr std::array<double, 2> WGS84Position{52.248091, 10.57417};
    constexpr std::array<double, 2> expectedResult{-113.3742031902, 116.8369533306};

    std::array<double, 2> result{wgs84::toCartesian(WGS84Reference, WGS84Position)};

    REQUIRE(expectedResult[0] == Approx(result[0]));
    REQUIRE(expectedResult[1] == Approx(result[1]));
}

TEST_CASE("From WGS84 to Cartesian: Compact notation") {
    constexpr std::array<double, 2> expectedResult{-113.3742031902, 116.8369533306};

    std::array<double, 2> result{wgs84::toCartesian({52.247041, 10.575830}, {52.248091, 10.57417})};

    REQUIRE(expectedResult[0] == Approx(result[0]));
    REQUIRE(expectedResult[1] == Approx(result[1]));
}

TEST_CASE("From WGS84 to Cartesian: Second example") {
    constexpr std::array<double, 2> WGS84Reference{52.247041, 10.575830};
    constexpr std::array<double, 2> WGS84Position{52.251011, 10.573568};
    constexpr std::array<double, 2> expectedResult{-154.48, 441.75};

    std::array<double, 2> result{wgs84::toCartesian(WGS84Reference, WGS84Position)};

    REQUIRE(expectedResult[0] == Approx(result[0]));
    REQUIRE(expectedResult[1] == Approx(result[1]));
}

TEST_CASE("From Cartesian to WGS84: WGS84 position identical to WGS84 reference") {
    constexpr std::array<double, 2> WGS84Reference{52.247041, 10.575830};
    constexpr std::array<double, 2> CartesianPosition{0.0, 0.0};
    constexpr std::array<double, 2> expectedResult{52.247041, 10.575830};

    std::array<double, 2> result{wgs84::fromCartesian(WGS84Reference, CartesianPosition)};

    REQUIRE(expectedResult[0] == Approx(result[0]));
    REQUIRE(expectedResult[1] == Approx(result[1]));
}

TEST_CASE("From Cartesian to WGS84: First example") {
    constexpr std::array<double, 2> WGS84Reference{52.247041, 10.575830};
    constexpr std::array<double, 2> CartesianPosition{-154.48, 441.75};
    constexpr std::array<double, 2> expectedResult{52.251011, 10.573568};

    std::array<double, 2> result{wgs84::fromCartesian(WGS84Reference, CartesianPosition)};

    REQUIRE(expectedResult[0] == Approx(result[0]));
    REQUIRE(expectedResult[1] == Approx(result[1]));
}

TEST_CASE("From Cartesian to WGS84: Compact notation") {
    constexpr std::array<double, 2> expectedResult{52.251011, 10.573568};

    std::array<double, 2> result{wgs84::fromCartesian({52.247041, 10.575830}, {-154.48, 441.75})};

    REQUIRE(expectedResult[0] == Approx(result[0]));
    REQUIRE(expectedResult[1] == Approx(result[1]));
}

TEST_CASE("From Cartesian to WGS84: Second example") {
    constexpr std::array<double, 2> WGS84Reference{52.247041, 10.575830};
    constexpr std::array<double, 2> CartesianPosition{-208.57, 431.07};
    constexpr std::array<double, 2> expectedResult{52.250915, 10.572776};

    std::array<double, 2> result{wgs84::fromCartesian(WGS84Reference, CartesianPosition)};

    REQUIRE(expectedResult[0] == Approx(result[0]));
    REQUIRE(expectedResult[1] == Approx(result[1]));
}

