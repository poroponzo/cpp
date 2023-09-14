#include <iostream>
#include "NetworkItem.h"
#include "PC.h"

// default constructor implementation
PC::PC() : NetworkItem(), memsize(2), mem(new int(2)) {
} 

// nondefault constructor implementation (per ora non worka)
PC::PC(std::string naim2, IP ippi2, int memory) : 
NetworkItem(naim2, ippi2), 
memsize(memory), 
mem(new int[memory]) {
    mem[0] = 4;
    mem[2] = 3;
} 


// method print implementation
void PC::Print() const {
    NetworkItem::Print();


// sta roba non serve però serve come feedback per vedere che non scriviamo cassate
    std::cout << "memory address: " << mem << std::endl;
    std::cout << "memory size: " << memsize << std::endl;
    std::cout << "memory content: " << std::endl;
    for (int k = 0; k < memsize; k++)
        std::cout << mem[k] << std::endl;
}

//method Size
int PC::Size() const{
    return memsize*sizeof(int);
}

// copy constructor implementation
// use the copy constructor of the NetworkItem class (to copy IP and itemname), then, copy also mem
// detta brutta, se il costruttore usava il costruttore di NI ora uso il costruttore di copia di NI
// il costruttore di PC inoltre diceva che esisteva mem come un new int(numero)
// ora ho un new int(*(other.mem)) ossia una nuova area di memoria, di tipo intero
// con dentro il contenuto della vecchia area di memoria puntata da other.mem
// other.mem è il puntatore a mem dell'altro oggetto PC, *(other.mem) è il contenuto di quella memoria

PC::PC(const PC& other) : NetworkItem(other), memsize(other.memsize), mem(new int(*(other.mem))) {
}

// method clone
NetworkItem* PC::clone() const {
    return new PC(*this); // restituisce un puntatore a PC
}


// default destructor implementation
PC::~PC() {
    // Dealloca la memoria quando l'oggetto viene distrutto
    delete mem;
}