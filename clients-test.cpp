#include "clients.h"
#include <iostream>

int main(int argc, char const *argv[]) {

clients::Clients Clients1("Einstein","Albert","EA9876");
clients::Clients Clients2("Einstein","Albert"," EA9876");
if(Clients1==Clients2){std::cout<<"egal";}else{std::cout<< "pas egal";}
std::cout << Clients1;


}
