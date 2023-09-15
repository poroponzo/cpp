#ifndef PC_H
#define PC_H
#include "NetworkItem.h"
#include "IP.h"
#include <iostream>


using namespace std;


class PC : public NetworkItem {
private:
	int* mem;

public:
	// Constructor
	PC(const string& itemName, const IP& ip, int size=0) : NetworkItem(itemName, ip), mem(new int[size]) {}

	// Copy constructor
	PC(const PC& other) : NetworkItem(other), mem(new int[other.Size()]) {
		for (int i = 0; i < Size(); i++) {
			mem[i] = other.mem[i];
		}
	}

	// Assignment operator
	PC& operator=(const PC& other) {
		if (this != &other) {
			NetworkItem::operator=(other);

			delete[] mem;
			mem = new int[other.Size()];

			for (int i = 0; i < Size(); i++) {
				mem[i] = other.mem[i];
			}
		}

		return *this;
	}

	// Destructor
	virtual ~PC() {
		delete[] mem;
	}

	// Size method
	virtual int Size() const {
		// IP address (array of 4 integers)
		return sizeof(int) * 4; //in byte
	}

	// Clone method
	virtual NetworkItem* clone() const {
		return new PC(*this);
	}

	// Print method
	virtual void Print() const {
		cout << "PC: " << ItemName << endl;
		m_ip.Print();
		
		


	}
};
#endif

