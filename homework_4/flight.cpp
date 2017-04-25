//
//  flight.cpp
//  tp_homework4
//
//  Created by Falcon on 18.03.17.
//  Copyright © 2017 falcon. All rights reserved.
//

#include <cstring>
#include <iostream>
#include "flight.hpp"
#include "time.hpp"

Flight::Flight(char const * const destination, int const number, char const * const aircraft_type) :
  destination(nullptr),
  number(0),
  aircraft_type(nullptr),
  time(),
  days_of_the_weak(nullptr)
{
  if (destination) {
    size_t len = strlen(destination) + 1;
    this->destination = new char[len];
    memcpy(this->destination, destination, len);
  }
  
  if (number) {
    this->number = number;
  }
  
  if (aircraft_type) {
    size_t len = strlen(aircraft_type);
    this->aircraft_type = new  char[len];
    memcpy(this->aircraft_type, aircraft_type, len);
  }
  
  days_of_the_weak = new int[number_day_of_the_weak];
  for (int i = 0; i < number_day_of_the_weak; i++)
    days_of_the_weak[i] = 0;
}

Flight::Flight(const Flight& rhs) :
  number(rhs.number),
  time(rhs.time)
{
  if (rhs.destination) {
    size_t len = strlen(rhs.destination) + 1;
    destination = new char[len];
    memcpy(destination, rhs.destination, len);
  }
  
  if (rhs.aircraft_type) {
    size_t len = strlen(rhs.aircraft_type) + 1;
    aircraft_type = new char[len];
    memcpy(aircraft_type, rhs.aircraft_type, len);
  }
  
  if (rhs.days_of_the_weak) {
    days_of_the_weak = new int[number_day_of_the_weak];
    for (int i = 0; i < number_day_of_the_weak; i++) {
      days_of_the_weak[i] = rhs.days_of_the_weak[i];
    }
  }
}

Flight& Flight::operator=(const Flight& rhs)
{
  if (this == &rhs) {
    return *this;
  }
  
  if (destination) {
    delete [] destination;
    destination = nullptr;
  }
  
  if (rhs.destination) {
    size_t len = strlen(rhs.destination) + 1;
    destination = new char[len];
    memcpy(destination, rhs.destination, len);
  }
  
  if (rhs.number) {
    number = rhs.number;
  }
  
  if (aircraft_type) {
    delete [] aircraft_type;
    aircraft_type = nullptr;
  }
  
  if (rhs.aircraft_type) {
    size_t len = strlen(rhs.aircraft_type) + 1;
    aircraft_type = new char[len];
    memcpy(aircraft_type, rhs.aircraft_type, len);
  }
  
  time = rhs.time;
  
  if (days_of_the_weak) {
    delete [] days_of_the_weak;
  }
  
  if (rhs.days_of_the_weak) {
      days_of_the_weak = new int[number_day_of_the_weak];
      for (int i = 0; i < number_day_of_the_weak; i++) {
        days_of_the_weak[i] = rhs.days_of_the_weak[i];
    }
  }
  
  return *this;
}

Flight::~Flight()
{
  delete[] destination;
  delete[] aircraft_type;
}

const char* Flight::get_destination() const
{
  return destination;
}

const int Flight::get_number() const
{
  return number;
}

const char* Flight::get_aircraft_type() const
{
  return aircraft_type;
}

const Time Flight::get_time() const
{
  return time;
}

const int* Flight::get_days_of_the_weak() const
{
  return days_of_the_weak;
}

const int Flight::check_day_of_the_weak(int number_of_the_day)
{
  if (days_of_the_weak) {
    if (days_of_the_weak[number_of_the_day])
      return 1;
  }
  return 0;
}

void Flight::set_destination(char const * const new_destination)
{
  if (destination) {
    delete [] destination;
    destination = nullptr;
  }
  
  if (new_destination) {
    size_t len = strlen(new_destination) + 1;
    destination = new char[len];
    memcpy(destination, new_destination, len);
  }
}

void Flight::set_number(int const new_number)
{
  number = new_number;
}

void Flight::set_aircraft_type(char const * const new_aircraft_type)
{
  if (aircraft_type) {
    delete aircraft_type;
    aircraft_type = nullptr;
  }
  
  if (new_aircraft_type) {
    size_t len = strlen(new_aircraft_type);
    aircraft_type = new char[len];
    memcpy(aircraft_type, new_aircraft_type, len);
  }
}

void Flight::set_time(int const hours, int const minutes)
{
  time.set_time(hours, minutes);
}

void Flight::add_day_of_the_weak(int const number_of_the_day)
{
  if (days_of_the_weak) {
    days_of_the_weak[number_of_the_day % 7] = 1;
  }
}

void Flight::delete_day_of_the_weak(int const number_of_the_day)
{
  if (days_of_the_weak) {
    days_of_the_weak[number_of_the_day % 7] = 0;
  }
}

void Flight::show_destination()
{
  if (destination) {
    std::cout << destination << std::endl;
  }
}

void Flight::show_number()
{
  std::cout << number << std::endl;
}

void Flight::show_aircraft_type()
{
  if (aircraft_type) {
    std::cout << aircraft_type << std::endl;
  }
}

void Flight::show_time()
{
  time.show_time();
}

void Flight::show_days_of_the_weak()
{
  if (days_of_the_weak) {
    for (int i = 0; i < number_day_of_the_weak; i++) {
      if (days_of_the_weak[i] == 1)
      switch (i) {
        case 0:
          std::cout << "Monday ";
          break;
        case 1:
          std::cout << "Tuesday ";
          break;
        case 2:
          std::cout << "Wednesday ";
          break;
        case 3:
          std::cout << "Thursday ";
          break;
        case 4:
          std::cout << "Friday ";
          break;
        case 5:
          std::cout << "Saturday ";
          break;
        case 6:
          std::cout << "Sunday ";
          break;
      }
    }
    std::cout << std::endl;
  }
}

void Flight::show_all()
{
  std::cout << "Flight number: ";
  show_number();
  std::cout << "Destination: ";
  show_destination();
  std::cout << "Aircraft_type: ";
  show_aircraft_type();
  std::cout << "Time: ";
  show_time();
  std::cout << "Flight days: ";
  show_days_of_the_weak();
}