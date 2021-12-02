

#include "date.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  Date dateTest(12,31,2021);
  std::cout << "Date: " << toString(dateTest) << std::endl;
  std::cout << "day #" << dayOfYear(dateTest) << std::endl;
  dateTest.next();
  std::cout << "Date++: " << toString(dateTest) << std::endl;
  dateTest.back();
  std::cout << "Date: " << toString(dateTest) << std::endl;
  return 0;
}