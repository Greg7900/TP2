#include "reservation.h"

#include <iostream>

int main(int argc, char const *argv[]) {
  date::Date date1(10,12,21);
  
  reservation::Reservation reservation1(date1,3,"single","3agc","3dx");
  std::cout << reservation1 << std::endl;
  
 
  return 0;
}