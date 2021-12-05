
#include "chambre.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  Chambre chambre1(150,217,"single");
  std::cout << chambre1 << std::endl;
  chambre1.updatePrix(240);
  chambre1.updateNumero(056);
  chambre1.updateType("double");
  std::cout << chambre1 << std::endl;
  return 0;
}