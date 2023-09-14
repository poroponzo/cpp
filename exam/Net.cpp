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

//costruisco una net con nome e ip dato, inoltre scelgo anche una lista di ip disponibili
Net::Net(std::string name, IP ippi, std::list<IP> ipavailable) : 
NetworkItem(name, ippi), 
IPList(ipavailable), 
NetItemList({}){
}


// print method for the Net class (override 'cause is not pure, sporco! lezzo! laido e non puro!)
void Net::Print() const{
// printa lista di identifier e lista di ip
}

//NB i return0 sono per testare alcuni metodi e non farlo rompere i coglioni
// print del size
int Net::Size() const{
    return 0;
}

//metodo add
bool Net::Add(NetworkItem* item){
    return 0;

}

// metodo addcopy
bool Net::AddCopy(const NetworkItem* item){
    return 0;

}


// metodo remove
bool Net::remove(const IP ipremove){
    return 0;
}

// method clone, da problemi
NetworkItem* Net::clone() const {
    return new Net(*this);
}

//distruttore
//vado nella itemlist, mi scorro a lista col for
//come se fossi in un enumerate di python
// il mio iteratore dovrebbe essere un puntatore a classe NetworkItem
//lo uccido per rilasciare la memoria

Net::~Net(){
    for (NetworkItem* element : NetItemList ) 
		delete  element;
}