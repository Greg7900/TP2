#include "clients.h"
#include <iostream>

namespace clients {
    Clients::Clients(std::string firstname, std::string lastname, std::string ID) : _firstname(firstname), _lastname(lastname), _ID(ID) {
    }



//Getter
    std::string Clients::Getfirstname() const {
        return _firstname;
    }

    std::string Clients::Getlastname() const {
        return _lastname;
    }

    std::string Clients::GetID() const {
        return _ID;
    }


    std::ostream& operator << (std::ostream& os,const Clients &clients) {
        os << clients.Getfirstname() + " " + clients.Getlastname() + " " +clients.GetID() <<std::endl;
        return os;
    }



//Setter
	void Clients::Setfirstname(std::string firstname){
	_firstname = firstname;
	}

    void Clients::Setlastname(std::string lastname){
	_lastname = lastname;
	}

	void Clients::SetID(std::string ID){
	_ID = ID;
	}

bool operator == (const Clients& c1,const Clients& c2) { // check for equality
        if( (c1.Getfirstname()==c2.Getfirstname()) && (c1.Getlastname()==c2.Getlastname())&& (c1.GetID()==c2.GetID())) {
            return true;
        }
    return false;
  }
}