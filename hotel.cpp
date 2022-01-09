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
   std::vector<chambre::Chambre> Hotel::chambre() const{
      return _Chambre;
   }
   
   int Hotel::NbChambre() const{

   	return _Chambre.size();
   }
   
   void Hotel::displayChambre()const{
      for(auto it=_Chambre.begin(); it!=_Chambre.end();it++){
         std::cout<<*it<<std::endl;
      }
   }
   
   bool Hotel::chambreAvailable(std::string type){
      for(auto it=_Chambre.begin(); it!=_Chambre.end();it++){
         chambre::Chambre chambre1=*it;
         if(chambre1.type()==type){
            return true;
         } 
      }
      return false;
   }
   int Hotel::displayPrice(std::string type){
      for(auto it=_Chambre.begin(); it!=_Chambre.end();it++){
         chambre::Chambre chambre1=*it;
         if(chambre1.type()==type){
            return chambre1.prix();
         } 
      }
      return 0;
   }
      int Hotel::chambreSelect(std::string type){
      int numero=32767;
      auto it_save= _Chambre.begin();
      chambre::Chambre chambre_save=*it_save;

      for(auto it=_Chambre.begin(); it!=_Chambre.end();it++){
         chambre::Chambre chambre1=*it;
         if(chambre1.type()==type){
            if((chambre1.numero()<numero)&&(chambre1.status()=="not reserved")){
               numero=chambre1.numero();
               it_save=it;
               chambre_save=*it_save;
            }
         }

         
         
      }chambre_save.updateStatus(1);
      *it_save=chambre_save;
      return numero;
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
   
   void afficheReduite(hotel::Hotel hotel){
      std::cout<< " Identifiant unique : " + hotel.idUnique() + " | Nom : " + hotel.nom()+ " | ville : "+ hotel.ville()+ " | Nombre de chambre : "+ std::to_string(hotel.NbChambre())<< std::endl;

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