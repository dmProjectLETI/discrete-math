#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{

private:
    int width, height;

public:
    Rectangle();
    Rectangle(int, int);
    ~Rectangle();
    int getArea();
    int getPerimetr();
    int getWidth();
    int getHeight();

};

#endif // RECTANGLE_H
