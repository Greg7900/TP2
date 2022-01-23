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
   
   bool Hotel::chambreAvailable(std::string type){ // verifie si l'hotel a ce type de chambre
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
   
   void Hotel::updateIdUnique(std::string idUnique){
   	_idUnique=idUnique;
   }
   
   void Hotel::updateNom(std::string nom){
   	_nom=nom;
   }
   
   void Hotel::updateVille(std::string ville){
   	_ville=ville;
   }
   
   void Hotel::ajouterChambre(chambre::Chambre Chambre){
   	_Chambre.push_back(Chambre);
   }
   void Hotel::delChambre(chambre::Chambre Chambre){
      auto it=std::find_if(_Chambre.begin(),_Chambre.end(),[Chambre](const chambre::Chambre& ch) {return Chambre.numero()==ch.numero();});
      if(it != _Chambre.end()){
      _Chambre.erase(it);
      std::cout<<" The room has been deleted "<<std::endl;
      }else{std::cout<<" room not found "<<std::endl;

  }
    
   }
   
   void afficheReduite(hotel::Hotel hotel){ // affichage de l'hotel sans les chambres
      std::cout<< " Identifiant unique : " + hotel.idUnique() + " | Nom : " + hotel.nom()+ " | ville : "+ hotel.ville()+ " | Nombre de chambre : "+ std::to_string(hotel.NbChambre())<< std::endl;

   }
   
   std::ostream& operator<<(std::ostream& os, const Hotel& hotel) { // affichage complet
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