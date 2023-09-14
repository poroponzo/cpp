
// A net (Net) is described by a list of pointers to generic network items (NetItemList) and by a
// list of IP addresses (IPList); it will have the methods for adding (Add() and AddCopy()) and
// removing elements (remove()).
// When an object of type Net is created, the IP list is initialized with a list of addresses. The method
// AddCopy(const NetworkItem* item) removes and IP from such a list and assigns it to
// the generic network item (item), then inserts a copy of this in the list NetItemList. To do this
// it is necessary to use the method Clone().
// The method Add(NetworkItem* item) removes an IP from the address list, assigns it to
// generic network item (item) and inserts it into the list NetItemList.
// The method remove(const IP ipremove) searches in a Net the generic network element
// with IP ipremove, removes the element from the list NetItemList and inserts the IP of the
// removed element into the list of available IPs.

// c'è una lista di ip liberi che chiamiamo IPList
// add pesca un ip da IPLIST, lo assegna ad un generico Item (perché Item è un NetworkItem quindi ha un IP
// e io creo un NetworkItem con Ip pescato da catapuòlta) 
//e lo aggiunbge a IpList NetItemList

//SOLARI E LA BAMBA AMICI PER LA PELLE


#ifndef NET_H
#define NET_H

#include <list>
#include <iostream>
#include "NetworkItem.h"

class Net : public NetworkItem{     

// list of IP addresses che posso assegnare a un Item
std::list<IP> IPList;

// list of pointers to generic network items
// ogni item è definito da Nome e IP e gli Ip li pesco da IPList con add, li rimuovo con remove
// addcopy fa come add ma inserisce una copia del network item
std::list<NetworkItem*> NetItemList;
// mi serve un corrispettivo di memsize per sapere uanto è lunga?
// posso avere due Ip uguali?

//mi serve sapere quanto è lunga la lista? forse no perché è iterabile con i:

public:

// default costructor
Net(); // inizializza string e IP con NetworkItem(), IPlist(default, vuota), NetItemList(default,vuota)

// alternative constructor 
// need a name, an IP (because it is a NetworkItem), and then also a NetItemList and an IpList
Net(std::string, IP, std::list<IP>);

// copy constructor
Net(const Net& other);

// cloning and referring to Networkitem
NetworkItem* clone() const;

// destructor
~Net();

//print definito per net
void Print() const override;

// print del size(pure virtual so no override)
int Size() const;

bool AddCopy(const NetworkItem* item);
bool Add(NetworkItem* item);
bool remove(const IP ipremove);



};
#endif
