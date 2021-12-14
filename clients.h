#include <iostream>

	namespace clients {
	class Clients{


	public:

		Clients(std::string firstname, std::string lastname, std::string ID);

			std::string Getfirstname() const;  
			std::string Getlastname() const;
			std::string GetID() const;

		void Setfirstname(std::string firstname);
		void Setlastname(std::string lastname);
		void SetID(std::string ID);

	private:

			std::string _firstname;
			std::string _lastname;
			std::string _ID;
	};

			std::string getFullName(const Clients &p);
			std::ostream& operator << (std::ostream& os,const Clients &clients);

}