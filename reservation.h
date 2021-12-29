#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include "date.h"
#include "clients.h"
#include "hotel.h"
namespace reservation{
class Reservation /*: public hotel*/{
public:
   Reservation(date::Date Ddate, int nightNbr, hotel::Hotel hotel,std::string type,clients::Clients client,int prix);
   date::Date Ddate() const;
   int nightNbr() const;
   //std::string type() const;
   clients::Clients client() const;
   hotel::Hotel hotel() const;
   int prix()const;
   void updateDdate(date::Date Ddate);
   void updatenightNbr(int nightNbr);
   void updateType(std::string type);
   void updateHotel(hotel::Hotel hotel);
   void updateClient(clients::Clients client);
   void updatePrix(int prix);
   
private:
   date::Date _Ddate;
   int _nightNbr;
   hotel::Hotel _hotel;
   std::string _type;
   clients::Clients _client;
   int _prix;
   
};

std::ostream& operator<<(std::ostream& os, const Reservation& reservation);
bool operator == (const Reservation& r1,const Reservation& r2);
#endif
}

//faire test available dans hotel pour connaitre la dispo dans l'hotel
//et faire test pour savoir il y a deja une reserv sur la chambre
