#include "hotel.h"
namespace hotel {
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
   void Hotel::displayChambre()const{
      for(auto it=_Chambre.begin(); it!=_Chambre.end();it++){
         std::cout<<*it<<std::endl;
      }
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
   void Hotel::updateNbChambre(chambre::Chambre nbChambre){
   	_Chambre.push_back(nbChambre);
   }
   
   std::ostream& operator<<(std::ostream& os, const Hotel& hotel) {
        os << " Identifiant unique : " + hotel.idUnique() + " | Nom : " + hotel.nom()+ " | ville : "+ hotel.ville()+ " | Nombre de chambre : "+ std::to_string(hotel.NbChambre())<< std::endl;

        hotel.displayChambre();

        return os;
    }
   bool operator == (const Hotel& h1,const Hotel& h2) { // check for equality
      if( (h1.idUnique()==h2.idUnique()) && (h1.nom()==h2.nom())&& (h1.ville()==h2.ville())) {
         return true;
        }
    return false;
  }
 }