//
//  Shape.cpp
//  homework_6
//
//  Created by Falcon on 04.04.17.
//  Copyright © 2017 falcon. All rights reserved.
//

#include "Shape.hpp"
#include <iostream>
#include <math.h>

Circle::Circle() :
radius(0),
x(0),
y(0)
{}

Circle::Circle(double radius) :
radius(radius),
x(0),
y(0)
{}

Circle::Circle(double radius, double x, double y) :
radius(radius),
x(x),
y(y)
{}

void Circle::about_figure()
{
  std::cout << "Type: Circle" << std::endl;
  std::cout << "Center: (" << x << ';' << y << ')' << std::endl;
  std::cout << "Radius = " << radius << std::endl;
  std::cout << "Area = " << get_area() << std::endl;
  std::cout << "Perimeter = " << get_perimeter() << std::endl;
  std::cout << std::endl;
}

double Circle::get_area() const
{
  return M_PI * radius * radius;
}

double Circle::get_perimeter() const
{
  return 2  / M_PI * radius;
}

double Circle::get_radius() const
{
  return radius;
}

double Circle::get_x() const
{
  return x;
}

double Circle::get_y() const
{
  return y;
}

void Circle::show_radius()
{
  std::cout << radius;
}

void Circle::show_center()
{
  std::cout << '(' << x << ';' << y << ')' << std::endl;
}

void Circle::set_radius(double radius)
{
  this->radius = radius;
}

void Circle::set_center(double x, double y)
{
  this->x = x;
  this->y = y;
}

Rectangle::Rectangle() :
length(0),
width(0)
{}

Rectangle::Rectangle(double length, double width):
length(length),
width(width)
{}

void Rectangle::about_figure()
{
  std::cout << "Type: Rectangle" << std::endl;
  std::cout << "Length = " << length << std::endl;
  std::cout << "Width = " << width << std::endl;
  std::cout << "Area = " << get_area() << std::endl;
  std::cout << "Perimeter = " << get_perimeter() << std::endl;
  std::cout << std::endl;
}

double Rectangle::get_area() const
{
  return length * width;
}

double Rectangle::get_perimeter() const
{
  return 2 * (length + width);
}

double Rectangle::get_length() const
{
  return length;
}

double Rectangle::get_width() const
{
  return width;
}

void Rectangle::show_length()
{
  std::cout << length << std::endl;
}

void Rectangle::show_width()
{
  std::cout << width << std::endl;
}

void Rectangle::set_lenth(double length)
{
  this->length = length;
}

void Rectangle::set_width(double width)
{
  this->width = width;
}
