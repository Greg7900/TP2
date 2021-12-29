
#include "chambre.h"
#include <assert.h> 
namespace chambre{
    Chambre::Chambre(int prix, int numero, std::string type) : _prix(prix), _numero(numero), _type(type) {}

    int Chambre::prix() const {
        return _prix;
    }

    int Chambre::numero() const {
        return _numero;
    }
    std::string Chambre::status() const {
        return _status;
    }
    std::string Chambre::type() const {
        return _type;
    }
    void Chambre::updatePrix(int prix){
        _prix= prix;
    }   
    void Chambre::updateNumero(int numero) {
         _numero = numero;
    }

    void Chambre::updateType(std::string type) {
        _type = type;
    }
    void Chambre::updateStatus(int status) {
        if(status==1){
            _status="reserved";
        }else{
            _status="not reserved";
        }
    }
    std::string toString(Chambre chambre){
        return  " prix : " + std::to_string(chambre.prix()) + " numero : " + std::to_string(chambre.numero()) + " type : "+ chambre.type()+" State = "+chambre.status(); ;
    }
    std::ostream& operator<<(std::ostream& os, const Chambre& chambre) {
        os << " prix : " + std::to_string(chambre.prix()) + " numero : " + std::to_string(chambre.numero())+ " type : "+ chambre.type()+" State = "+chambre.status();
        return os;
    }
}