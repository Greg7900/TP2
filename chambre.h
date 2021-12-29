#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <iostream>
namespace chambre{
class Chambre {
public:
   Chambre(int prix, int numero, std::string type);
   int prix() const;
   int numero() const;
   std::string  status() const;
   std::string type() const;
   void updatePrix(int prix);
   void updateNumero(int numero);
   void updateType(std::string type);
   void updateStatus(int status);
private:
   int _prix;
   int _numero;
   std::string _type;
   std::string _status="not reserved";
};
std::string toString(Chambre chambre);

std::ostream& operator<<(std::ostream& os, const Chambre& chambre);
#endif

}