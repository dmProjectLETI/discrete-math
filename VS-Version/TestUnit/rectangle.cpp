#include "rectangle.h"
#include <iostream>

int width, height;

Rectangle::Rectangle()
{
    width = 0;
    height = 0;
}

Rectangle::~Rectangle()
{
    std::cout << "destroy!" << std::endl;
}

Rectangle::Rectangle(int width, int height)
{
    this->width = width;
    this->height = height;
}

int Rectangle::getArea()
{
    return width * height;
}

int Rectangle::getPerimetr()
{
    return width + height;
}

int Rectangle::getWidth()
{
    return width;
}

int Rectangle::getHeight()
{
    return height;
}
