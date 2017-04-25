//
//  Shape.hpp
//  homework_6
//
//  Created by Falcon on 04.04.17.
//  Copyright © 2017 falcon. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>

class Shape
{
  public:
  virtual ~Shape() = default;
  virtual void about_figure() = 0;
  virtual double get_area() const = 0;
  virtual double get_perimeter() const = 0;
};

class Circle : public Shape
{
  public:
  Circle();
  Circle(double radius);
  Circle(double radius, double x, double y);
  
  void about_figure();
  
  double get_area() const;
  double get_perimeter() const;
  
  double get_radius() const;
  double get_x() const;
  double get_y() const;

  void show_radius();
  void show_center();
  
  void set_radius(double radius);
  void set_center(double x, double y);
  
  private:
  double radius;
  double x;
  double y;
};

class Rectangle : public Shape
{
  public:
  Rectangle();
  Rectangle(double length, double width);
  
  void about_figure();
  
  double get_area() const;
  double get_perimeter() const;
  
  double get_length() const;
  double get_width() const;
  
  void show_length();
  void show_width();
  
  void set_lenth(double length);
  void set_width(double width);
  
  private:
  double length;
  double width;
};

#endif /* Shape_hpp */
