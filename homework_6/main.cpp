//
//  main.cpp
//  homework_6
//
//  Created by Falcon on 01.04.17.
//  Copyright © 2017 falcon. All rights reserved.
//

#include <iostream>
#include "Shape.hpp"

int main(int argc, const char * argv[]) {
  Shape* m[10];
  
  for (int i = 0; i < 5; i++)
    m[i] = new Circle(i, i+1, i - 1);
  
  
  for (int i = 5; i < 10; i++)
    m[i] = new Rectangle(i + 1, i - 1);
  
  for (int i = 0; i < 10; i++)
    m[i]->about_figure();
  
  for (int i = 0; i < 10; i++) {
    delete m[i];
  }
    
  return 0;
}
