#include "reservation.h"

#include <iostream>


namespace reservation{

Reservation::Reservation(date::Date Ddate, int nightNbr, hotel::Hotel hotel,std::string type,int roomNumber,clients::Clients client,int idReserv) : 
_Ddate(Ddate), _nightNbr(nightNbr),_hotel(hotel),_type(type),_roomNumber(roomNumber), _client(client),_idReserv(idReserv)
{
	CalculPrix();
	
}
int Reservation::idReserv() const{
	return _idReserv;
}
int Reservation::roomNumber() const{
	return _roomNumber;
}
int Reservation::prix()const{
	return _prix;
}

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
void Reservation::updateNightNbr(int nightNbr){
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
void Reservation::CalculPrix(){
	int prix=_hotel.displayPrice(_type);
	_prix=_nightNbr*prix;
}
 

std::ostream& operator<<(std::ostream& os, const Reservation& reservation){
	
	os << " idReserv: " ;os << reservation.idReserv()<<std::endl;os<< " idClient: " ;os << reservation.client() << " idHotel: " ; afficheReduite(reservation.hotel());os<<" Numero de chambre : "<<reservation.roomNumber()<<std::endl;os<< " Nombre de nuits : " <<reservation.nightNbr()<<" jour(s)"<<std::endl; os<< " Type: " ;os<< reservation.type()<<std::endl<< " date de debut: ";
	os<<reservation.Ddate();
	os<< " Prix total de la réservation :";os<<reservation.prix()<<" euros\n";
    return os;
    }


bool operator == (const Reservation& r1,const Reservation& r2){
        if( (r1.Ddate()==r2.Ddate()) && (r1.client()==r2.client())&& (r1.hotel()==r2.hotel()) && r1.type()==r2.type()) {
            return true;
        }
    return false;
  }
}