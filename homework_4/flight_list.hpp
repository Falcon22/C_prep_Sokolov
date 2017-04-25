//
//  flight_list.hpp
//  tp_homework4
//
//  Created by Falcon on 23.03.17.
//  Copyright © 2017 falcon. All rights reserved.
//

#ifndef flight_list_hpp
#define flight_list_hpp

#include <stdio.h>
#include "flight.hpp"

struct Flight_list {
  Flight* list;
  int size;
  
  Flight_list();
  Flight_list(const Flight_list& rhs);
  ~Flight_list();
  
  Flight_list& operator=(const Flight_list& rhs);
  
  
  void add_flight(const Flight& new_flight);
  void delete_last_flight();
  
  void show_flights_to_destination(char const * const destination);
  void show_flights_on_the_day_of_week(int const number_of_the_day);
  void show_flights_to_time(int const number_of_the_day, int const hours, int const minutes);
};

#endif /* flight_list_hpp */
