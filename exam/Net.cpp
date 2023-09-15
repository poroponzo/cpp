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
    // Identifier list printer
        std::cout<< "Net Print method invoked:"<< std::endl;
        std::cout<< "List of items connected to the net:" << std::endl;
    for (NetworkItem* item : NetItemList) {
        std::cout << item->GetName() << std::endl;
    }
    std::cout<< "IP still available:" << std::endl;
    // IP print using print method of IP (funziona)
    for (IP address : IPList) {
        address.print();
    }
}

//NB i return0 sono per testare alcuni metodi e non farlo rompere i coglioni
// print del size
int Net::Size() const{
    int size = 0;
    for (NetworkItem* item : NetItemList) {
    size = size + item->Size();
    }
    return size;
}

//metodo add

bool Net::Add(NetworkItem* item){
    
    if(IPList.size()>0) { //mi chiedo se ho ancora IP disponibili
    IP iptemp = IPList.front(); //estraggo primo IP
    IPList.remove(iptemp); //Rimuovo quel IP dalla lista dei disponibili
    item->setip(iptemp); // setto IP dell'item passato con quello estratto
    NetItemList.push_back(item); //aggiungo item alla lista degli oggetti connessi
    std::cout<< "Item added to the net" << std::endl;
    return true;
    }
    else {
        std::cout << "not enough IP addresses available"<< std::endl;
        return false;
    }
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

// copy constructor
Net::Net(const Net& other) : NetworkItem(other), IPList(other.IPList), NetItemList(other.NetItemList) {
}

//distruttore
//vado nella itemlist, mi scorro a lista col for
//come se fossi in un enumerate di python
// il mio iteratore dovrebbe essere un puntatore a classe NetworkItem
//lo uccido per rilasciare la memoria

Net::~Net(){
    // siccome possono essere PC dovrebbero già uccidersi con il loro distruttore
    // for (NetworkItem* element : NetItemList ) 
	// 	delete  element;
}