
#include "hotel.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  hotel::Hotel hotel1("OCEAN11","Le Bellagio","Las Vegas");
  hotel::Hotel hotel2("OCEAN11","Le Bellagio","Las Vegas");

  chambre::Chambre chambre1(170,317,"single");

  chambre::Chambre chambre2(200,252,"double");
  chambre::Chambre chambre4(200,22,"double");
  chambre::Chambre chambre5(200,574,"double");

  chambre::Chambre chambre3(200,10,"suite");
  chambre::Chambre chambre30(200,106,"suite");
  
  std::cout << hotel1 << std::endl;

  hotel1.updateNbChambre(chambre1);
  std::cout << hotel1 << std::endl;

  hotel1.updateNbChambre(chambre2);
  
  hotel1.updateNbChambre(chambre4);
  hotel1.updateNbChambre(chambre5);
  hotel1.updateNbChambre(chambre30);
  hotel1.updateNbChambre(chambre3);


  std::cout << hotel1 << std::endl;

  if(hotel1==hotel2)
    {
      std::cout<<"true"<<std::endl;
    }else{
      std::cout<<"false"<<std::endl;
    }
  
  if(hotel1.chambreAvailable("suite")){std::cout<< "chambre du type disponible"<<std::endl;}
  //afficheReduite(hotel1);
  std::cout<<hotel1.chambreSelect("double")<<std::endl;
  std::cout << hotel1 << std::endl;
  std::cout<<hotel1.chambreSelect("suite")<<std::endl;
  std::cout << hotel1 << std::endl;
  std::cout<<hotel1.chambreSelect("double")<<std::endl;
  std::cout << hotel1 << std::endl;



  return 0;
}