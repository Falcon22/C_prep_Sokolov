//
//  flight.hpp
//  tp_homework4
//
//  Created by Falcon on 18.03.17.
//  Copyright © 2017 falcon. All rights reserved.
//

#ifndef flight_hpp
#define flight_hpp

#include <stdio.h>
#include <ctime>
#include "time.hpp"

class Flight
{
  public:
  Flight(char const * const destinatiom = nullptr, int const number = 0, char const * const aircraft_type = nullptr);
  Flight(const Flight& rhs);
  ~Flight();
  
  Flight& operator=(const Flight& rhs);
  
  const char* get_destination() const;
  const int get_number() const;
  const char* get_aircraft_type() const;
  const Time get_time() const;
  const int* get_days_of_the_weak() const;
  
  const int check_day_of_the_weak(int number_of_the_day);
  
  void set_destination(char const * const new_destination);
  void set_number(int const new_number);
  void set_aircraft_type(char const * const new_aircraft_type);
  void set_time(int const hours, int const minutes);
  
  void add_day_of_the_weak(int const number_of_the_day);
  void delete_day_of_the_weak(int const number_of_the_day);
  
  void show_destination();
  void show_number();
  void show_aircraft_type();
  void show_time();
  void show_days_of_the_weak();
  void show_all();
  
  private:
  char* destination;
  int number;
  char* aircraft_type;
  Time time;
  const int number_day_of_the_weak = 7;
  int* days_of_the_weak;
  
  
};

#endif /* flight_hpp */
