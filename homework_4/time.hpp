//
//  time.hpp
//  tp_homework4
//
//  Created by Falcon on 23.03.17.
//  Copyright © 2017 falcon. All rights reserved.
//

#ifndef time_hpp
#define time_hpp

#include <stdio.h>

class Time
{
  public:
  Time();
  Time(int hours, int minutes);
  
  void show_time();
  void set_time(int const hours, int const minutes);
  
  int get_minutes() const;
  
  private:
  int hours;
  int minutes;
  
};

#endif /* time_hpp */
