#include "reservation.h"
#include <iostream>
//#include <algorithm>
void SaisieReserv (std::vector<clients::Clients>& tab,std::vector<reservation::Reservation>& res, hotel::Hotel& hotel){

  std::string nom, prenon, idClient,type, idhotel;
  
  std::cout<< " Enter Customer firstname : " ;
  std::cin>> prenon;
  std::cout<< " Enter Customer lastname : " ;
  std::cin>> nom;
  std::cout<< " Enter Customer ID : " ;
  std::cin>> idClient;
  clients::Clients client(prenon, nom, idClient);
  if(std::find(tab.begin(),tab.end(),client)!=tab.end())
  {
    std::cout<< " Client déja saisie !!!"<<std::endl;
  }else{
    std::cout<< " Le client a été saisie !"<<std::endl;
    tab.push_back(client);
  }
  std::cout << std::endl;


  int day, month, year, nightnbr, choix=0;
  do{
    std::cout<< " Enter Reservation day : " ;
    std::cin>> day;
    std::cout<< " Enter Reservation month : " ;
    std::cin>> month;
    std::cout<< " Enter Reservation year : " ;
    std::cin>> year;
    if(date::isDate(month,day,year)==false)
      {std::cout<<" The date is invalid !!!"<<std::endl;
      }
}while(date::isDate(month,day,year)==false);
  date::Date date(month,day,year);

  std::cout<< " Enter night number : " ;
  std::cin>> nightnbr;
  if(nightnbr>1){
  }else{
    std::cout<< " The night number is invalid !!!" ;
    std::cin>> nightnbr;
  }
  
  std::cout<< " Enter your room type : " ;
  std::cout<< " Press 1 for : single, 2 for double and 3 for suite" <<std::endl;
  std::cin>>choix;
  switch (choix) {
    case 1: type= "single";break;
    case 2: type= "double";break;
    case 3: type= "suite";break;
  }
  std::cout << " You choose the "<<type<< " type"<<std::endl;
  int prix=nightnbr*hotel.displayPrice(type), roomNumber=0;                    // calcul du prix
  
    if(hotel.chambreAvailable(type))                               // test de validité de la chambre
    { 
      roomNumber=hotel.chambreSelect(type);
      std::cout<<roomNumber;
      reservation::Reservation reservation1(date,nightnbr,hotel,type,roomNumber,client,prix);
      if(res.size()==0){
        res.push_back(reservation1);
        std::cout<< " La reservation a été saisie !"<<std::endl;
      }else{


        for(auto it=res.begin();it!=res.end();it++){
         reservation::Reservation reservationTest=*it;
         if(reservation1.roomNumber()==4/*reservationTest.roomNumber()*/){
            if( (reservationTest.nightNbr()+reservationTest.Ddate() )< (reservation1.Ddate()) ){
            std::cout<< " Reservation déja saisie !!! "<<std::endl;
            }else{
            std::cout<< " La reservation a été saisie !"<<std::endl;
            res.push_back(reservation1);
          }
          }else{
            res.push_back(reservation1);
          }

      
        }
      }

   }else{
      std::cout<< "Chambre non disponiple"<<std::endl;
   }

std::cout << std::endl;
}

  
std::ostream& operator<<(std::ostream& os, const std::vector<clients::Clients>& vect) {
  os << "Client :"<<std::endl;
  os << " ";
  for (auto number : vect)
    os << number << " ";
  os << std::endl;
  return os;
}
std::ostream& operator<<(std::ostream& os, const std::vector<reservation::Reservation>& reser) {
  int i=1;
  os<< "----------------------------------------------------Reservation----------------------------------------------------"<<std::endl;
  for (auto number : reser){
    os<< "Reservation numero "<<i<<":"<<std::endl;
    os << number << " "<< std::endl;
    i++;
  }
  os<< "--------------------------------------------------------Fin--------------------------------------------------------"<<std::endl;
  return os;
}


int main(int argc, char const *argv[]) {

  std::vector<clients::Clients> tabClient;
  std::vector<reservation::Reservation> Reserv;
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
  

  clients::Clients client11 ("Jean","michel","AZERTY");
  clients::Clients client12 ("Pierre","pan","qsdfg");
  clients::Clients client13 ("g","g","g");
  tabClient.push_back(client11);
  tabClient.push_back(client12);
  tabClient.push_back(client13);
  std::cout<<tabClient;
  while(1){
  SaisieReserv(tabClient,Reserv,hotel1);
  
  std::cout<<Reserv;
}
  
  return 0;


	}
  