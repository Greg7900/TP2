#include "reservation.h"

#include <iostream>

int main(int argc, char const *argv[]) {
  date::Date date1(10,12,21);
  hotel::Hotel hotel1("OCEAN11","Le Bellagio","Las Vegas");
  clients::Clients client1 ("Jean","michel","AZERTY");
  reservation::Reservation reservation1(date1,3,hotel1,"single",client1);
  std::cout << reservation1 << std::endl;
  
 
  return 0;
}