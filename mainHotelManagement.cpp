#include "reservation.h"
#include <iostream>

//#include <algorithm>
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
  os<< "------------------------------------------------Liste des Reservations---------------------------------------------"<<std::endl;
  for (auto number : reser){
    os<< "Reservation numero "<<i<<":"<<std::endl;
    os << number << " "<< std::endl;
    i++;
  }
  os<< "--------------------------------------------------------Fin--------------------------------------------------------"<<std::endl;
  return os;
}
void displayReserv (reservation::Reservation& res, int choix){
        std::cout << std::endl;
        if(choix==1){
        std::cout << "\033[2J\033[1;1H"; //clear terminal//clear terminal
        std::cout<< "---------------------------------------------Reservation saisie---------------------------------------------"<<std::endl;
        std::cout<<res;
        std::cout<< "------------------------------------------------------------------------------------------------------------"<<std::endl;
      }else if(choix==2){
        std::cout<<res;
      }
}
int roomselect (std::string type,std::vector<reservation::Reservation>& res,hotel::Hotel& hotel){

  int numero=32767;
  

    for(auto it=hotel.chambre().begin(); it!=hotel.chambre().end();it++){
       chambre::Chambre chambre1=*it;
       
      for(auto it1=res.begin();it1!=res.end();it1++){
      reservation::Reservation reservationTest=*it1;
   
       if(chambre1.type()==type){
          if((chambre1.numero()<numero)&&(reservationTest.roomNumber()!=chambre1.numero())){
             numero=chambre1.numero();    
          }
       }
      }
    }

    std::cout << hotel<< std::endl;
    
  
return numero;
}

void searchReserv (std::vector<reservation::Reservation>& res, hotel::Hotel& hotel){
        std::string idClient;
        int flag=0;
        std::cout<< " Enter Customer ID : " ;
        std::cin>> idClient;
        for(auto it=res.begin();it!=res.end();it++){
         reservation::Reservation reservationTest=*it;
         if(reservationTest.client().GetID()==idClient){
          displayReserv(reservationTest,1);
          flag=1;
        }
        if(flag==0){std::cout<< " Reservation not found";}
      }
      
}
 void custumerReserv(std::vector<reservation::Reservation>& res, hotel::Hotel& hotel){
      std::cout << "\033[2J\033[1;1H"; //clear terminal
      int flag=0;
      std::string idClient;
      std::cout<< " Enter Customer ID or name : " ;
      std::cin>> idClient;
      std::cout<< "---------------------------------------------Reservation saisie---------------------------------------------"<<std::endl;
      for(auto it=res.begin();it!=res.end();it++){
         reservation::Reservation reservationTest=*it;
         if(reservationTest.client().GetID()==idClient){
          displayReserv(reservationTest,2); // 2 pour pouvoir afficher plusieurs reservation si choix = 1  un clear du terminal s'executera et un ne pourra voir que la derniere reservation
          flag=1;
         }else if(reservationTest.client().Getlastname()==idClient){
          displayReserv(reservationTest,2); // 2 pour pouvoir afficher plusieurs reservation 
          flag=1;
         }
      }
      if(flag==0){std::cout<< " Reservation not found";}
      std::cout<< "------------------------------------------------------------------------------------------------------------"<<std::endl;
      

 }

clients::Clients custumerInformation (void){
  
  std::string nom, prenon, idClient;
  std::cout << std::endl;
  std::cout<< "---------------------------------------------Enter a Reservation----------------------------------------------"<<std::endl;
  std::cout<< " Enter Customer firstname : " ;
  std::cin>> prenon;
  std::cout<< " Enter Customer lastname : " ;
  std::cin>> nom;
  std::cout<< " Enter Customer ID : " ;
  std::cin>> idClient;
  clients::Clients client(prenon, nom, idClient);
  return client;
 }

date::Date reservDate (void){
  int day=0, month=0, year=0; 
  
  do{
   
    std::cout<< " Enter Reservation day : " ;
    std::cin>> day; if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  } // pour eviter les boucles infinies causés par le cin lors d'une saisie autre que string
    std::cout<< " Enter Reservation month : " ;
    std::cin>> month;if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  }
    std::cout<< " Enter Reservation year : " ;
    std::cin>> year;if(std::cin.fail()) { std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  }
    if(date::isDate(month,day,year)==false)
      {std::cout<<" The date is invalid !!!"<<std::endl;
      }
}while(date::isDate(month,day,year)==false);
  date::Date date(month,day,year);
  return date;
}


void createReserv (std::vector<clients::Clients>& tab,std::vector<reservation::Reservation>& res, hotel::Hotel& hotel){
  std::cout << "\033[2J\033[1;1H"; //clear terminal
  std::string type, idhotel;
  clients::Clients client=custumerInformation();
  if(std::find(tab.begin(),tab.end(),client)!=tab.end())
  {
    std::cout<< " customer already entered !!!"<<std::endl;
  }else{
    std::cout<< " customer has been entered !"<<std::endl;
    tab.push_back(client);
  }
  std::cout << std::endl;

  date::Date date=reservDate();


  std::cout<< " Enter night number : " ;
  int nightnbr;
  std::cin>> nightnbr;
  if(nightnbr>=1){
  }else{
    std::cout<< " The night number is invalid !!!" ;
    std::cout<< " Enter night number : " ;
    std::cin>> nightnbr;
  }
  
  std::cout<< " Enter your room type : "   <<std::endl;
  std::cout<< "    Press 1 for : Single "  <<std::endl;
  std::cout<< "    Press 2 for : Double "  <<std::endl;
  std::cout<< "    Press 3 for : Suite "   <<std::endl;
  int choix;
  std::cin>>choix;
  switch (choix) {
    case 1: type= "single";std::cout << " You choose the "<<type<< " type"<<std::endl;break;
    case 2: type= "double";std::cout << " You choose the "<<type<< " type"<<std::endl;break;
    case 3: type= "suite"; std::cout << " You choose the "<<type<< " type"<<std::endl;break;
    default :
    type="UNKNOWN";std::cout << " You choose a "<<type<< " type !!! "<<std::endl;break;
  }
  
  
  
   if(hotel.chambreAvailable(type))                               // test de validité de la chambre
    { 
      int idReserv=res.size()+1;
      int roomNumber=roomselect(type,res,hotel);
      reservation::Reservation reservation1(date,nightnbr,hotel,type,roomNumber, client,idReserv);
      
      if(res.size()>=0){
        res.push_back(reservation1);
        displayReserv(reservation1,1);
        
      }else{


        for(auto it=res.begin();it!=res.end();it++){
         reservation::Reservation reservationTest=*it;
         if(reservation1.roomNumber()==reservationTest.roomNumber()){

            if( (reservationTest.nightNbr()+reservationTest.Ddate() )< (reservation1.Ddate()) ){
            std::cout<< " The reservation already entered !!! "<<std::endl;
            }else{
            std::cout<< " The reservation has been entered !"<<std::endl;
            res.push_back(reservation1);
            displayReserv(reservation1,1);
          }
          }else{
            res.push_back(reservation1);
            displayReserv(reservation1,1);
          }

      
        }
      }

   }else{
      std::cout<< " Unavailable Chamber " <<std::endl;
   }


}
void modifyReserv (std::vector<reservation::Reservation>& res){
    std::cout << "\033[2J\033[1;1H"; //clear terminal
    int choix,flag;
    std::string ID;
    std::cout<< " Enter an action ! " <<std::endl<<" Modify date : 1"<<std::endl<<" Modify night number : 2 "<<std::endl<<" Modify client information : 3 "<<std::endl<<" Modify chamber type : 4 ";
    std::cin>>choix;
    std::cout<< " You have chosen the number "<<choix<<std::endl;
    
    std::cout<< " Enter Customer ID : " ;
    std::cin>>ID;
    
    date::Date date1=reservDate(); 

    auto it_save=res.begin();  // Pour trouver la reservation à modifier pour rapport au nom et a la date de reserv initial
    reservation::Reservation reservationSauv=*it_save;

    for(auto it=res.begin();it!=res.end();it++){
      reservation::Reservation reservationTest=*it;
      if( (reservationTest.client().GetID()==ID)&& (reservationTest.Ddate()==date1) ){
            
               
               it_save=it;
               reservationSauv=*it_save;
            
         }
         *it_save=reservationSauv;
    }
    switch (choix){
      case 1 :
      {
        date::Date date=reservDate();
        reservationSauv.updateDdate(date);
        std::cout<<res;
      }
      
      
      break;
      case 2 :
      {
        int nightnumber;
        std::cout<<" Enter the new night number : "<<std::endl;
        std::cin>>nightnumber;
        reservationSauv.updateNightNbr(nightnumber);
        std::cout<<res;
      }
      break;
      case 3 :
      {
        clients::Clients client=custumerInformation();
        reservationSauv.updateClient(client);
        std::cout<<res;
      }
      break;
      case 4 :
      {
        std::string type;
        std::cout<<" Enter the new chamber type : "<<std::endl;
        std::cin>>type;
        reservationSauv.updateType(type);
        std::cout<<res;
      }
      break;

    }
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
  std::cout<< "---------------------------------------------Info Hotel---------------------------------------------"<<std::endl<<std::endl;
  std::cout << hotel1 << std::endl;
  std::cout<< "----------------------------------------------------------------------------------------------------"<<std::endl;

  clients::Clients client11 ("Jean","michel","AZERTY");
  clients::Clients client12 ("Pierre","pan","qsdfg");
  clients::Clients client13 ("g","g","g");
  tabClient.push_back(client11);
  tabClient.push_back(client12);
  tabClient.push_back(client13);
  clients::Clients client1 ("Jean","michel","AZERTY");
  date::Date datee(4,02,2022); //mois day
  reservation::Reservation reservation1(datee,3,hotel1,"single",217,client1,5);
  Reserv.push_back(reservation1);
  clients::Clients client114 ("test","test1","az");
  date::Date datee1(4,4,4); //mois day
  reservation::Reservation reservation11(datee1,3,hotel1,"single",207,client114,6);
  Reserv.push_back(reservation11);
  std::cout<<tabClient;
  while(1){
    int choix;
    std::cout<< " Enter an action ! " <<std::endl<<" Enter a reservation : 1"<<std::endl<<" Display a specific reservation : 2 "<<std::endl<<" View a customer's reservations : 3 "<<std::endl;
    std::cout<<" Modify a reservations : 4 "<<std::endl;
    std::cin>>choix;
    std::cout<< " You have chosen the number "<<choix<<std::endl;
    switch (choix){
      case 1 :
      createReserv(tabClient,Reserv,hotel1);
      break;
      case 2 :
      searchReserv(Reserv,hotel1);
      break;
      case 3 :
      custumerReserv(Reserv,hotel1);
      break;
      case 4 :
      modifyReserv(Reserv);
      break;

    }
  
  
  
  }
  
  
return 0;
}
  