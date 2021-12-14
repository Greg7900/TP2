#include "reservation.h"
#include "hotel.h"
#include <iostream>


int main(int argc, char const *argv[]) {
  
  Hotel hotel1("OCEAN11","Le Bellagio","Las Vegas");
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

  std::vector<clients::Clients> tabClient;
  clients::Clients client11 ("Jean","michel","AZERTY");
  clients::Clients client12 ("Pierre","pan","qsdfg");
  clients::Clients client13 ("paul","brun","mlmkj");
  tabClient.push_back(client11);
  tabClient.push_back(client12);
  tabClient.push_back(client13);
  for(auto it=tabClient.begin(); it!=tabClient.end();it++){
         std::cout<<*it<<std::endl;
      }

  return 0;


	}