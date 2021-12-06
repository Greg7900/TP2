#include "hotel.h"

   Hotel::Hotel(std::string idUnique, std::string nom, std::string ville, int nombredechambre ): _idUnique(idUnique), _nom(nom),_ville(ville), _nombredechambre(nombredechambre){}
   
   //int nb=nombredechambre();
   //std::array<int, nb> nbChambre;

   std::string  Hotel::idUnique() const{
   	return _idUnique;
   }
   std::string  Hotel::nom() const{
   	return _nom;
   }
   std::string Hotel::ville() const{
   	return _ville;
   }
   int Hotel::nombredechambre() const{
   	return _nombredechambre;
   }
   
   void Hotel::updateIdUnique(std::string idUnique){
   	_idUnique=idUnique;
   }
   void Hotel::updateNom(std::string nom){
   	_nom=nom;
   }
   void Hotel::updateVille(std::string ville){
   	_ville=ville;
   }
   void Hotel::updateNbChambre(int nombredechambre){
   	_nombredechambre=nombredechambre;
   }
   std::ostream& operator<<(std::ostream& os, const Hotel& hotel) {
        os << "Identifiant unique :" + hotel.idUnique() + " Nom : " + hotel.nom()+ " ville : "+ hotel.ville()+ " Nombre de chambre : "+ std::to_string(hotel.nombredechambre());
        return os;
    }