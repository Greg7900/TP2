#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
#include <vector>

class Hotel {

public:
   Hotel(std::string idUnique, std::string nom, std::string ville);
   std::string  idUnique() const;
   std::string  nom() const;
   std::string ville() const;
   int NbChambre() const;

   void updateIdUnique(std::string idUnique);
   void updateNom(std::string nom);
   void updateVille(std::string ville);
   void updateNbChambre(int nbChambre);
  
private:
   std::string _idUnique;
   std::string _nom;
   std::string _ville;
   int _nombredechambre;
   std::vector<std::string> _Chambre;
   



	
};
std::ostream& operator<<(std::ostream& os, const Hotel& hotel) ;
#endif