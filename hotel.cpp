#include "hotel.h"

   Hotel::Hotel(std::string idUnique, std::string nom, std::string ville): _idUnique(idUnique), _nom(nom),_ville(ville){}
   
   
   

   std::string  Hotel::idUnique() const{
   	return _idUnique;
   }
   std::string  Hotel::nom() const{
   	return _nom;
   }
   std::string Hotel::ville() const{
   	return _ville;
   }
   int Hotel::NbChambre() const{

   	return _Chambre.size();
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
   void Hotel::updateNbChambre(int nbChambre){
   	_Chambre.resize(nbChambre);
   }
   std::ostream& operator<<(std::ostream& os, const Hotel& hotel) {
        os << "Identifiant unique : " + hotel.idUnique() + " Nom : " + hotel.nom()+ " ville : "+ hotel.ville()+ " Nombre de chambre : "+ std::to_string(hotel.NbChambre());
        return os;
    }