// implement circle.cpp functions here.
#include <numbers>
#include <cmath>
#include "circle.h"

double radius(double x1, double y1, double x2, double y2){
    return sqrt(pow((x2-x1), 2) + pow((y2-y1),2));

}

double circumference(double rad){
    return 2* rad * std::numbers::pi;
}

double area(double rad){
    return std::numbers::pi * rad * rad;
}