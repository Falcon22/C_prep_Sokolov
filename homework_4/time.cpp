//
//  time.cpp
//  tp_homework4
//
//  Created by Falcon on 23.03.17.
//  Copyright © 2017 falcon. All rights reserved.
//

#include "time.hpp"
#include <iostream>

Time::Time() {
  hours = 0;
  minutes = 0;
}

Time::Time(int hours, int minutes) {
  this->hours = (hours + (minutes / 60)) % 24;
  this->minutes = minutes % 60;
}

void Time::show_time() {
  std::cout << hours / 10 << hours % 10 << ":" << minutes / 10 << minutes % 10 << std::endl;
}

void Time::set_time(int const new_hours, int const new_minutes) {
  hours = new_hours;
  minutes = new_minutes;
}

int Time::get_minutes() const
{
  return hours*60 + minutes;
}
