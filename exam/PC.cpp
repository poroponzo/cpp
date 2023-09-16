#include <iostream>
#include "NetworkItem.h"
#include "PC.h"

// default constructor implementation
PC::PC() : 
NetworkItem(), 
memsize(2), 
mem(new int[memsize]) {
} 

// nondefault constructor implementation (per ora non worka)
PC::PC(std::string naim2, IP ippi2, int memory) : 
NetworkItem(naim2, ippi2), 
memsize(memory), 
mem(new int[memory]){
} 

//copy constructor
PC::PC(const PC& other) : 
NetworkItem(other), 
mem(new int[other.memsize]), 
memsize(other.memsize){
	for (int k = 0; k < memsize; k++) 
		mem[k] = other.mem[k];
}

// method print implementation
void PC::Print() const {
    NetworkItem::Print();
// rich print, non desired function can be commented out
    std::cout << "memory address: " << mem << std::endl;
    std::cout << "memory size: " << memsize << std::endl;
    std::cout << "memory content: " << std::endl;
    for (int k = 0; k < memsize; k++){
        std::cout << mem[k] << std::endl;
    }
    std::cout<< "______________________________" << std::endl;
}

//method Size
int PC::Size() const{
    return memsize*sizeof(int);
}

// method clone
NetworkItem* PC::clone() const {
    return new PC(*this);
}

// metodo settare memoria implementazione
PC& PC::SetMemory(int *memory, int size) {
	if (size > memsize) {
		size = memsize;
		std::cout << "Warning: not enough memory, data might be lost!" << std::endl;
	}
	for (int k = 0; k < size; k++) 
		mem[k] =  memory[k];
	return *this;
}

// default destructor implementation
PC::~PC() {
    // Dealloca la memoria quando l'oggetto viene distrutto
    delete[] mem;
}
