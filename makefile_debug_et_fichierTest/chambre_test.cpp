
#include "chambre.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  chambre::Chambre chambre1(150,217,"single");
  //std::cout<< toString(chambre1)<<std::endl;
  //std::cout << chambre1 << std::endl;
  chambre1.updatePrix(240);
  //chambre1.updateNumero(056);
  chambre1.updateType("double");
  chambre1.updateStatus(1);
  std::cout << chambre1 << std::endl;
  return 0;
}