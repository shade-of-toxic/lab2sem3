#include "cardioid.hpp"
#include <iostream>

void exit(Cardioid &card)
{
  exit(0);
}

void seta(Cardioid &card)
{
  std::cout << "Input a>>";
  double a;
  std::cin >> a;
  card.setA(a);
}

void geta(Cardioid &card)
{
  std::cout << "The value of 'a' parameter is " << card.getA();
}
void getr(Cardioid &card)
{
  std::cout << "Input angle>>";
  double a;
  std::cin >> a;
  std::cout << "Polar radius in point " << a << " radians is " << card.getR(a);
}

void getmlfa(Cardioid &card)
{
  std::cout << "Maximum distanse from cardioid axis to it's border is " << card.getMaxLengthFromAxis();
}

void getrofc(Cardioid &card)
{
  std::cout << "Input angle>>";
  double a;
  std::cin >> a;
  std::cout << "Radius of curvative in point " << a << " radians is " << card.getRadiusOfCurvative(a);
}

void getarea(Cardioid &card)
{
  std::cout << "Area of cardioid is " << card.getArea();
}

void getarclen(Cardioid &card)
{
  std::cout << "Input angle>>";
  double a;
  std::cin >> a;
  std::cout << "Arc length of cardioid in point " << a << " radians is " << card.getArcLength(a);
}

void (*options[])(Cardioid &card) = {exit, seta, geta, getr, getmlfa, getrofc, getarea, getarclen};

int main()
{
  Cardioid cardioid{0};
  while (1)
  {
    std::cout << "Choose... \n\
    [0]Exit\n\
    [1]Set 'a'\n\
    [2]Get 'a'\n\
    [3]Get polar radius\n\
    [4]Get max length from axis\n\
    [5]Get radius of curvative\n\
    [6]Get area\n\
    [7]Get arc length\n>>";
    int choice;
    std::cin >> choice;
    if(choice > 7 || choice < 0) {
      std::cout << "Try again!\n";
      continue;
    }
    options[choice](cardioid);
    std::cout << std::endl;
  }
}