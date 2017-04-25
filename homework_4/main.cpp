//
//  main.cpp
//  tp_homework4
//
//  Created by Falcon on 18.03.17.
//  Copyright © 2017 falcon. All rights reserved.
//

#include <iostream>
#include "flight_list.hpp"
#include "flight.hpp"
#include <cstring>

int main(int argc, const char * argv[]) {
  Flight p1("Amsterdam", 1488, "Boeing");
  p1.set_time(4, 20);
  p1.add_day_of_the_weak(1);
  p1.add_day_of_the_weak(2);
  p1.add_day_of_the_weak(3);
  Flight_list l;
  
  Flight p2;
  p2.set_destination("London");
  p2.set_number(11);
  p2.set_aircraft_type("Tu-134");
  p2.set_time(13, 20);
  p2.add_day_of_the_weak(3);
  
  Flight p3 = p2;
  Flight p4(p3);
  p2 = p4;
  l.Flight_list::add_flight(p1);
  l.Flight_list::add_flight(p2);
  l.Flight_list::add_flight(p3);
  l.Flight_list::add_flight(p4);
  l.Flight_list::delete_last_flight();
  l.show_flights_to_destination((char*)"London");
  
  return 0;
}
