#ifndef NETWORKITEM_H
#define NETWORKITEM_H
#include "IP.h"
#include <string>

class NetworkItem{
protected:
std::string ItemName; //identifier
IP m_ip; //IP address

public:
//constructor default
NetworkItem();

//constructor using id and ip
NetworkItem(std::string, IP);

// Dichiarazione del costruttore di copia
NetworkItem(const NetworkItem& other); 

// print and size methods 
virtual void Print()const; // virtual but not pure, must be implemented in .cpp
virtual int Size()const =0; //pure virtual, no implementation in .cpp
virtual NetworkItem* clone() const =0; //pure virtual, no implementation in .cpp

// default destructor
~NetworkItem();

};
#endif

