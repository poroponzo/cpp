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
    std::cout<< "______________________________" << std::endl;
    std::cout<< "IP still available:" << std::endl;
    // IP print using print method of IP (funziona)
    if (IPList.size()>0){
    for (IP address : IPList) {
        address.print();
        }
    }
    else {
        std::cout<<"No more IP available"<< std::endl;
    }
    
    std::cout<< "______________________________" << std::endl;
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

//metodo add, verificato
bool Net::Add(NetworkItem* item){
    
    if(IPList.size()>0) { //mi chiedo se ho ancora IP disponibili
        IP iptemp = IPList.front(); //estraggo primo IP
        IPList.remove(iptemp); //Rimuovo quel IP dalla lista dei disponibili
        item->setip(iptemp); // setto IP dell'item passato con quello estratto
        NetItemList.push_back(item); //aggiungo item alla lista degli oggetti connessi
        std::cout<< "Item added to the net" << std::endl;
        std::cout<< "______________________________" << std::endl;
        return true;
    }
    else {
        std::cout << "not enough IP addresses available"<< std::endl;
        return false;
    }
}

// metodo addcopy, verificato
bool Net::AddCopy(const NetworkItem* item){
    if(IPList.size()>0) { //mi chiedo se ho ancora IP disponibili
        IP iptemp = IPList.front(); //estraggo primo IP
        IPList.remove(iptemp); //Rimuovo quel IP dalla lista dei disponibili
        // a differenza di Add, qui faccio un clone e poi uso il clone
        NetworkItem* copy = item->clone();
        copy->setip(iptemp); // setto IP dell'item passato con quello estratto
        NetItemList.push_back(copy); //aggiungo item alla lista degli oggetti connessi
        std::cout<< "Item added to the net" << std::endl;
        return true;
    }
    else {
        std::cout << "not enough IP addresses available"<< std::endl;
        return false;
    }

}

// metodo remome
/* search for the item in NetItemList with IP == ipremove
remove it from the List and insert its ip in the IPLIST
possible errosrs are managed*/
bool Net::remove(const IP ipremove){
    // size of NetItemList must be greater then zero otherwise i discover antimatter
    if( NetItemList.size()>0)
    {   //flag to know if i removed something
        int flag =0;

        //read all element in the list
        for(NetworkItem* item : NetItemList)
        {   
            // if an element ensure the ip to be removed
            //i remove the object and put the ip in the iplist
            // nb it is used the methdo getip 'cause ip is private in networkitem
            // so a method get and set is implemented in the virtual class
            if(item->getip() == ipremove){
                // remove from the list
                NetItemList.remove(item);
                // ad the ip to the other list
                IPList.push_back(ipremove);
                flag =1;
                std::cout << "item deleted from the net" << std::endl;
                std::cout << "following IP is again available:" << std::endl;
                ipremove.print();
                std::cout<< "______________________________" << std::endl;
                return true;   
            }
        }
        if(flag = 0) // so if the list is not empty but there is no item that match the IP
        std::cout << "ERROR: No such device" << std::endl;
        std::cout<< "______________________________" << std::endl;
        return false;        
    }
    else { //if the list is empty
        std::cout <<"ERROR: empty NetItemList" << std::endl;
        std::cout<< "______________________________" << std::endl;
        return false;
    }
}

// method clone, non ancora testato.
NetworkItem* Net::clone() const {
    return new Net(*this);
}

// copy constructor
Net::Net(const Net& other) : 
NetworkItem(other), 
IPList(other.IPList), 
NetItemList(other.NetItemList) {
}


//destructor
Net::~Net(){
    // siccome possono essere PC dovrebbero già uccidersi con il loro distruttore
    // for (NetworkItem* element : NetItemList ) 
	// 	delete  element;
}