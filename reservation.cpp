#include "reservation.h"

#include <iostream>


namespace reservation{

Reservation::Reservation(date::Date Ddate, int nightNbr, int NumChambre, std::string idHotel,std::string idClient) : _Ddate(Ddate), _nightNbr(nightNbr),_NumChambre(NumChambre),_idHotel(idHotel),_idClient(idClient){}



date::Date Reservation::Ddate() const{
	return _Ddate;
}
int Reservation::nightNbr() const{
	return _nightNbr;
}
int Reservation::NumChambre() const{
	return _NumChambre;
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
void Reservation::updateNumChambre(int NumChambre){
	_NumChambre=NumChambre;
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
	os << " idClient :" + reservation.idClient() + " idHotel : " + reservation.idHotel()+ " NumChambre : "+ std::to_string(reservation.NumChambre())+ " date de debut : "+ toString(reservation.Ddate());
    return os;
    }

}