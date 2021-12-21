#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
#include "chambre.h"
#include <vector>
namespace hotel {
class Hotel {

public:
   Hotel(std::string idUnique, std::string nom, std::string ville);
   std::string  idUnique() const;
   std::string  nom() const;
   std::string ville() const;
   int NbChambre() const;
   void displayChambre()const;

   void updateIdUnique(std::string idUnique);
   void updateNom(std::string nom);
   void updateVille(std::string ville);
   void updateNbChambre(chambre::Chambre nbChambre);
  
private:
   std::string _idUnique;
   std::string _nom;
   std::string _ville;
   int _nombredechambre;
   std::vector<chambre::Chambre> _Chambre;
   



	
};
std::ostream& operator<<(std::ostream& os, const Hotel& hotel) ;
bool operator== (const Hotel& h1,const Hotel& h2);
#endif
}