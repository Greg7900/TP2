
#include "hotel.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  Hotel hotel1("OCEAN11","Le Bellagio","Las Vegas");
  chambre::Chambre chambre1(170,217,"single");
  chambre::Chambre chambre2(200,252,"double");

  std::cout << hotel1 << std::endl;
  hotel1.updateNbChambre(chambre1);

  sstd::cout << hotel1 << std::endl;
  hotel1.updateNbChambre(chambre2);
  std::cout << hotel1 << std::endl;
  
  return 0;
}