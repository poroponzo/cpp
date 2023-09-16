#ifndef NET_H
#define NET_H

#include <list>
#include <iostream>
#include "NetworkItem.h"

class Net : public NetworkItem{     

// list of IP addresses che posso assegnare a un Item
std::list<IP> IPList;

// list of pointers to generic network items
std::list<NetworkItem*> NetItemList;

public:

// default costructor
Net(); // inizializza string e IP con NetworkItem(), IPlist(default, vuota), NetItemList(default,vuota)

// alternative constructor 
// need a name, an IP (because it is a NetworkItem), and then also a NetItemList and an IpList
Net(std::string, IP, std::list<IP>);

// copy constructor
Net(const Net& other);

// cloning and referring to Networkitem
// clone deve clonare un network item e poi inserirlo in itemlist
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
