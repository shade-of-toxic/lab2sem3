#include "cardioid.hpp"
#include "catch.hpp"
#include <cmath>

TEST_CASE("sets a & gets a") {
  Cardioid a;
  a.setA(10);
  REQUIRE(a.getA() == 10);
}

TEST_CASE("gives right arc length") {
  Cardioid a(2);
  CHECK(a.getArcLength(pi<double> / 2) == 16 - 8 * sqrt(2));
  CHECK(a.getArcLength(2 * pi<double>) == 32);
}

TEST_CASE("gives max length from axis") {
  Cardioid a(2);
  // double maxl = 0;
  // for (double i = 0; i < 2*pi<double>; i+=pi<double>/64) {
  //   if(a.getR(i) > maxl)
  //     maxl = a.getR(i);
  // }
  // CHECK(maxl == a.getMaxLengthFromAxis());
  // not from axis but from center of polar grid
  // not need to check it, its always 3a
  // so i just go
  CHECK(a.getMaxLengthFromAxis() == 6);
}

TEST_CASE("calculates right area") {
  Cardioid a(20);
  CHECK(a.getArea() ==
        2400 * pi<double>); // i can check other cases but theres no need cause
                            // it only follows formula
  // it just CANT work wrong
}

TEST_CASE("gives radius of curvative") {
  Cardioid a(10);
  double ch = std::fabs(
      (40. * std::sqrt(2.)) / 3. -
      a.getRadiusOfCurvative(
          pi<double> /
          2.)); // calculates the abs val of difference between analitically
                // solved equasion and formula for radius of curv of cardioid
                // for computational reasons values differ from each other

  CHECK(ch < 0.01); // so we compare them this way
}
