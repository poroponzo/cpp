#include <iostream>
#include "NetworkItem.h"
#include "Net.h"
// costurttore
// distruttore
//costruttore di copie
// clone

// default constructor
Net::Net() : NetworkItem(), 
IPList({IP(), IP(), IP()}), 
NetItemList({}){
}


//nbondefault constructor
// fare gli altri costruttori per tutte le altre possibilità??

Net::Net(std::string name, IP ippi, std::list<IP> ippione) : 
NetworkItem(name, ippi), 
IPList(ippione), 
NetItemList({}){
}


// print method for the Net class (override 'cause is not pure, sporco! lezzo! laido e non puro!)
void Net::Print() const{
// printa lista di identifier e lista di ip
}

// print del size
int Net::Size() const{
}

// metodo addcopy
bool Net::AddCopy(const NetworkItem* item){
}

//metodo add
bool Net::Add(NetworkItem* item){
}

// metodo remove
bool Net::remove(const IP ipremove){
}

//distruttore
