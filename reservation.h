#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include "date.h"
#include "clients.h"
namespace reservation{
class Reservation {
public:
   Reservation(date::Date Ddate, int nightNbr, int NumChambre, std::string idHotel,std::string idClient);
   date::Date Ddate() const;
   int nightNbr() const;
   int NumChambre() const;
   std::string idClient() const;
   std::string idHotel() const;

   void updateDdate(date::Date Ddate);
   void updatenightNbr(int nightNbr);
   void updateNumChambre(int NumChambre);
   void updateidHotel(std::string idHotel);
   void updateidClient(std::string idClient);
   void updatePrixTot(int nightNbr);
private:
   date::Date _Ddate;
   int _nightNbr;
   int _NumChambre;
   std::string _idHotel;
   std::string _idClient;
   double _prixTot;
   
};

double CalculPrix(int nightNbr);
std::ostream& operator<<(std::ostream& os, const Reservation& reservation);
#endif
}