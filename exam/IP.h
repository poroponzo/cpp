#ifndef IP_H
#define IP_H
#include <iostream>

class IP{
int ip[4]; // portotype of the class

public:
// default costructor 
IP(); //nell'implementazione dico che sono 4 random (nel cpp)
IP(int, int, int, int);

// Dichiarazione del costruttore di copia
IP(const IP& other); 

int GetOctet(int index) const; //dichiarazione metodo per ottenere otteti

//questo va cancellato, serve per testing
void print() const;

// definisco l'operatore == perché mi serve nel metodo list.remove()
bool operator==(const IP& other) const;

// default destructor
~IP();

};

// default 192.168.1.1
#endif
