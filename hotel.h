#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
#include "chambre.h"
#include <vector>
#include <algorithm>
namespace hotel {
class Hotel {

public:
   Hotel(std::string idUnique, std::string nom, std::string ville);
   std::string  idUnique() const;
   std::string  nom() const;
   std::string ville() const;
   std::vector<chambre::Chambre> chambre() const;
   int NbChambre() const;
   //double prixChambre() const;
   void displayChambre()const;
   void updateIdUnique(std::string idUnique);
   void updateNom(std::string nom);
   void updateVille(std::string ville);
   void updateNbChambre(chambre::Chambre nbChambre);
   bool chambreAvailable(std::string type);
   void setReserved(int roomState,int numChambre);
   int displayPrice(std::string type) ;
   int chambreSelect(std::string type);
private:
   std::string _idUnique;
   std::string _nom;
   std::string _ville;
   int _nombredechambre;
   std::vector<chambre::Chambre> _Chambre;
   



	
};
void afficheReduite (hotel::Hotel hotel);
std::ostream& operator<<(std::ostream& os, const Hotel& hotel) ;
bool operator== (const Hotel& h1,const Hotel& h2);
#endif
}