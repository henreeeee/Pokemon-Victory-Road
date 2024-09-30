#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
#include "Vector2D.h"
using namespace std;

class Point2D
{
public:
    double x;
    double y;

    Point2D();
    Point2D(double in_x, double in_y);
    
};

double GetDistanceBetween(Point2D, Point2D);

//https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
ostream& operator<<(ostream&, Point2D);
Point2D operator+(Point2D, Vector2D);
Vector2D operator-(Point2D, Point2D);

#endif