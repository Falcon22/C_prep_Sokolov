//
//  flight_list.cpp
//  tp_homework4
//
//  Created by Falcon on 23.03.17.
//  Copyright © 2017 falcon. All rights reserved.
//

#include "flight_list.hpp"
#include <cstring>
#include <iostream>

Flight_list::Flight_list() :
  size(0),
  list(nullptr)
{}

Flight_list::Flight_list(const Flight_list& rhs) :
  size(rhs.size)
{
  if (list) {
    delete [] list;
    list = nullptr;
  }
  
  if (rhs.list) {
    list = new Flight[size];
    for (int i = 0; i < size; i++) {
      list[i] = rhs.list[i];
    }
  }
}

Flight_list& Flight_list::operator=(const Flight_list& rhs)
{
  if (this == &rhs) {
    return *this;
  }
  
  if (list) {
    delete[] list;
    list = nullptr;
  }
  
  if (rhs.list) {
    size = rhs.size;
    list = new Flight[size];
    for (int i = 0; i < size; i++) {
      list[i] = rhs.list[i];
    }
  }
  
  return *this;
}

Flight_list::~Flight_list()
{
  delete[] list;
}

void Flight_list::add_flight(const Flight& new_flight)
{
  if (list) {
  Flight* nw = new Flight[size + 1];
  nw[size] = new_flight;
    for (int i = 0; i < size; i++)
      nw[i] = list[i];
    delete[] list;
  list = nw;
  size++;
  } else
  {
    size = 1;
    list = new Flight[size];
    list[0] = new_flight;
  }
}

void Flight_list::delete_last_flight()
{
  if (list) {
    size--;
    if (size) {
    Flight* nw = new Flight[size];
    for (int i = 0; i < size; i++)
      nw[i] = list[i];
    delete[] list;
    list = nw;
    }
  }
}

void Flight_list::show_flights_to_destination(char const * const destination)
{
  if (list) {
    for (int i = 0; i < size; i++) {
      if (strcmp(list[i].Flight::get_destination(), destination) == 0)
        list[i].show_all();
      std::cout << std::endl;
    }
  }
}

void Flight_list::show_flights_on_the_day_of_week(int const number_of_the_day)
{
  if (list) {
    for (int i = 0; i < size; i++) {
      if (list[i].Flight::check_day_of_the_weak(number_of_the_day))
        list[i].show_all();
      std::cout << std::endl;
    }
  }
}

void Flight_list::show_flights_to_time(int const number_of_the_day, int const hours, int const minutes)
{
  if (list) {
    for (int i = 0; i < size; i++) {
      if ((list[i].Flight::check_day_of_the_weak(number_of_the_day) == 0) && (list[i].Flight::get_time().Time::get_minutes() > (hours * 60 + minutes)))
        list[i].show_all();
      std::cout << std::endl;
    }
  }
}
