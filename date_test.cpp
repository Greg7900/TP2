

#include "date.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  date::Date dateTest(12,31,2027);
  date::Date dateTest1(12,31,2022);
  if(dateTest>dateTest1){std::cout<<"sup"<<std::endl;}else {std::cout<<"inf"<<std::endl;}
  std::cout << "Date: " << dateTest << std::endl;
  std::cout << "day #" << dayOfYear(dateTest) << std::endl;
  dateTest.next();
  std::cout << "Date++: " <<dateTest << std::endl;
  dateTest.back();
  std::cout << "Date --: " << dateTest << std::endl;
  return 0;
}