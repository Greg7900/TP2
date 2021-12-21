
#include "hotel.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  hotel::Hotel hotel1("OCEAN11","Le Bellagio","Las Vegas");
  chambre::Chambre chambre1(170,217,"single");
  chambre::Chambre chambre2(200,252,"double");
hotel::Hotel hotel2("OCEAN11","Le Bellagio","Las Vegas");
  std::cout << hotel1 << std::endl;
  hotel1.updateNbChambre(chambre1);

  std::cout << hotel1 << std::endl;
  hotel1.updateNbChambre(chambre2);
  std::cout << hotel1 << std::endl;
  if(hotel1==hotel2)
    {
      std::cout<<"true";
    }else{
      std::cout<<"false";
    }
  
  return 0;
}