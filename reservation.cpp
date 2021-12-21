#include "reservation.h"

#include <iostream>


namespace reservation{

Reservation::Reservation(date::Date Ddate, int nightNbr, hotel::Hotel hotel,std::string type,clients::Clients client) : 
_Ddate(Ddate), _nightNbr(nightNbr),_hotel(hotel),_type(type),_client(client){}



date::Date Reservation::Ddate() const{
	return _Ddate;
}
int Reservation::nightNbr() const{
	return _nightNbr;
}
std::string Reservation::type() const{
	return _type;
}
clients::Clients Reservation::client() const{
	return _client;
}
hotel::Hotel Reservation::hotel() const{
	return _hotel;
}

void Reservation::updateDdate(date::Date Ddate){
	_Ddate=Ddate;
}
void Reservation::updatenightNbr(int nightNbr){
	_nightNbr=nightNbr;
}
void Reservation::updateType(std::string type){
	_type=type;
}
void Reservation::updateHotel(hotel::Hotel  hotel){
	_hotel=hotel;
}
void Reservation::updateClient(clients::Clients client){
	_client=client;
}
void Reservation::updatePrixTot(int nightNbr){
	_prixTot=(215*nightNbr);
	
}


std::ostream& operator<<(std::ostream& os, const Reservation& reservation){
	os<< "----------------------------------------------------Reservation----------------------------------------------------"<<std::endl;
	os << " idClient: " ;os << reservation.client() << " idHotel: " ;os << reservation.hotel() << " Type: " ;os<< reservation.type()<<std::endl<< " date de debut: ";os<<reservation.Ddate();
    os<< "--------------------------------------------------------Fin--------------------------------------------------------"<<std::endl;
    return os;
    }


bool operator == (const Reservation& r1,const Reservation& r2){
        if( (r1.Ddate()==r2.Ddate()) && (r1.client()==r2.client())&& (r1.hotel()==r2.hotel()) && r1.type()==r2.type()) {
            return true;
        }
    return false;
  }
}