#include <iostream>
#include "NetworkItem.h"

// default constructor
NetworkItem::NetworkItem() : ItemName("default"), m_ip(192, 168, 1, 1) {
}    

// not default constructor
NetworkItem::NetworkItem(std::string neim, IP ippi) : ItemName(neim), m_ip(ippi) {
}

void NetworkItem::setip(IP nuovoip) {
    m_ip = nuovoip; //lo devo scrivere così perché non è un costruttore

}

// Implementazione del distruttore
NetworkItem::~NetworkItem() {
}

//Implementazione del costruttore di copia
NetworkItem::NetworkItem(const NetworkItem& other) : ItemName(other.ItemName), m_ip(other.m_ip) {
}


// implementazione metodo print
void NetworkItem::Print() const {       
    std::cout << "Item identifier: " <<  ItemName << std::endl;
    std::cout << "IP address: "; 
    m_ip.print();
}




