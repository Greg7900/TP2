
#include "hotel.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  Hotel hotel1("OCEAN11","Le Bellagio","Las Vegas");
  std::cout << hotel1 << std::endl;
  hotel1.updateNbChambre(10);
  std::cout << hotel1 << std::endl;
  hotel1.updateNbChambre(5);
  std::cout << hotel1 << std::endl;
  
  return 0;
}