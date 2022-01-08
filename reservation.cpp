#include "reservation.h"

#include <iostream>


namespace reservation{

Reservation::Reservation(date::Date Ddate, int nightNbr, hotel::Hotel hotel,std::string type,int roomNumber,clients::Clients client,int prix) : 
_Ddate(Ddate), _nightNbr(nightNbr),_hotel(hotel),_type(type),_roomNumber(roomNumber),_client(client),_prix(prix){}

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
void Reservation::updateRoonumber(int roomNumber){
	_roomNumber=roomNumber;
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
void Reservation::updatePrix(int prix){
	_prix=prix;
}
/*double Reservation::prixTot() {
	if(_type=="single"){
		_prixTot=(100*_nightNbr);
	}else if(_type=="double"){
		_prixTot=(125*_nightNbr);
	}else if(_type=="suite"){
		_prixTot=(210*_nightNbr);
	}
	return _prixTot;	
}*/


std::ostream& operator<<(std::ostream& os, const Reservation& reservation){
	//os<< "----------------------------------------------------Reservation----------------------------------------------------"<<std::endl;
	os << " idClient: " ;os << reservation.client() << " idHotel: " ; afficheReduite(reservation.hotel()); os<< " Nombre de nuits : " <<reservation.nightNbr()<<" jour(s)"<<std::endl; os<< " Type: " ;os<< reservation.type()<<std::endl<< " date de debut: ";
	os<<reservation.Ddate();
	os<< " Prix total de la réservation :";os<<reservation.prix()<<" euros"<<std::endl;
    //os<< "--------------------------------------------------------Fin--------------------------------------------------------"<<std::endl;
    return os;
    }


bool operator == (const Reservation& r1,const Reservation& r2){
        if( (r1.Ddate()==r2.Ddate()) && (r1.client()==r2.client())&& (r1.hotel()==r2.hotel()) && r1.type()==r2.type()) {
            return true;
        }
    return false;
  }
}