#include "reservation.h"

#include <iostream>

int main(int argc, char const *argv[]) {
  date::Date date1(10,12,21);
  hotel::Hotel hotel1("OCEAN11","Le Bellagio","Las Vegas");
  chambre::Chambre chambre1(100,1,"single");
  chambre::Chambre chambre2(100,2,"single");
  chambre::Chambre chambre3(100,3,"single");
  chambre::Chambre chambre4(125,4,"double");
  chambre::Chambre chambre5(125,5,"double");
  chambre::Chambre chambre6(125,6,"double");
  chambre::Chambre chambre7(125,7,"double");
  chambre::Chambre chambre8(125,8,"double");
  chambre::Chambre chambre9(210,9,"suite");
  chambre::Chambre chambre10(210,10,"suite");

 
  hotel1.updateNbChambre(chambre1);
  hotel1.updateNbChambre(chambre2);
  hotel1.updateNbChambre(chambre3);
  hotel1.updateNbChambre(chambre4);
  hotel1.updateNbChambre(chambre5);
  hotel1.updateNbChambre(chambre6);
  hotel1.updateNbChambre(chambre7);
  hotel1.updateNbChambre(chambre8);
  hotel1.updateNbChambre(chambre9);
  hotel1.updateNbChambre(chambre10);
  std::cout << hotel1 << std::endl;
  clients::Clients client1 ("Jean","michel","AZERTY");
  reservation::Reservation reservation1(date1,3,hotel1,"single",217,client1);
  std::cout << reservation1 << std::endl;
  


 /* std::cout<<" Numero de chambre : "<<reservation1.chambreSelect("double")<<std::endl;
  std::cout << reservation1 << std::endl;
  std::cout<<" Numero de chambre : "<<reservation1.chambreSelect("suite")<<std::endl;
  std::cout << reservation1 << std::endl;
  std::cout<<" Numero de chambre : "<<reservation1.chambreSelect("double")<<std::endl;
  std::cout << reservation1 << std::endl;*/
  
 
  return 0;
}