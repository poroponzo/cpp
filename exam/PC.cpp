#include <iostream>
#include "NetworkItem.h"
#include "PC.h"

// default constructor implementation
PC::PC() : NetworkItem(), memsize(8), mem(new int(8)) {
} 

// nondefault constructor implementation (per ora non worka)
PC::PC(std::string naim2, IP ippi2, int memory) : 
NetworkItem(naim2, ippi2), 
memsize(memory), 
mem(new int[memory]) { } 
// qua è dove davi mem[0] = 1 ecc. 
// non va bene perchè se mem è lungo 2 e tu gli dai mem[8]=9 lui scrive in un punto a caso della ram e spacca tutto

//copy constructor
PC::PC(const PC& other) : NetworkItem(other) , mem(new int[other.memsize]), memsize(other.memsize){
	for (int k = 0; k < memsize; k++) 
		mem[k] = other.mem[k];
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

// method clone
NetworkItem* PC::clone() const {
    return new PC(*this); // restituisce un puntatore a PC
}

// metodo settare memoria implementazione
PC& PC::SetMemory(int *memory, int size) {
	if (size > memsize) {
		size = memsize;
		std::cout << "Warinig: not enough memory, data might be lost!" << std::endl;
	}
	for (int k = 0; k < size; k++) 
		mem[k] =  memory[k];
	return *this;
}

// default destructor implementation
PC::~PC() {
    // Dealloca la memoria quando l'oggetto viene distrutto
    delete mem;
}
