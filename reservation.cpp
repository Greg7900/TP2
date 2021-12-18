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
std::string Reservation::idClient() const{
	return _idClient;
}
std::string Reservation::idHotel() const{
	return _idHotel;
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
void Reservation::updateidHotel(std::string idHotel){
	_idHotel=idHotel;
}
void Reservation::updateidClient(std::string idClient){
	_idClient=idClient;
}
void Reservation::updatePrixTot(int nightNbr){
	_prixTot=(215*nightNbr);
	
}


std::ostream& operator<<(std::ostream& os, const Reservation& reservation){
	os << " --> idClient: " + reservation.idClient() + " | idHotel: " + reservation.idHotel()+ " | type: "+ reservation.type()+ " | date de debut: "+ toString(reservation.Ddate());
    return os;
    }


bool operator == (const Reservation& r1,const Reservation& r2){
        if( (r1.Ddate()==r2.Ddate()) && (r1.idClient()==r2.idClient())&& (r1.idHotel()==r2.idHotel()) && r1.type()==r2.type()) {
            return true;
        }
    return false;
  }
}