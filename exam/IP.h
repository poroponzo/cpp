#ifndef IP_H
#define IP_H
#include <iostream>

class IP{
int ip[4]; // portotype of the class

public:
// default costructor 
IP(); //nell'implementazione dico che sono 4 random (nel cpp)
IP(int, int, int, int);
IP(const IP& other); // Dichiarazione del costruttore di copia

int GetOctet(int index) const; //dichiarazione metodo per ottenere otteti

//questo va cancellato, serve per testing
void print() const;

// default destructor
~IP();

};

// default 192.168.1.1
#endif
