#ifndef NETWORKITEM_H
#define NETWORKITEM_H
#include "IP.h"
#include <iostream>

using namespace std;

/*class NetworkItem {
protected:
	string ItemName;
	IP m_ip;
public:

	NetworkItem(const string& name, int a, int b, int c, int d) : ItemName(name), m_ip(a, b, c,d) {}
	virtual ~NetworkItem() {}
	virtual void Print()const = 0; 
	
	virtual int Size()const = 0;
	virtual NetworkItem* clone() const = 0;
	
};
*/



class NetworkItem {
protected:
	string ItemName;
	IP m_ip;

public:
	// Constructor
	NetworkItem(const string& name, const IP& ip) : ItemName(name), m_ip(ip) {}

	// Getter methods
	const string& getName() const { return ItemName; }
	const IP& getIP() const { return m_ip; }

	// Virtual methods
	virtual void Print() const {
		cout << "Item name: " << ItemName;
		m_ip.Print();
	}

	virtual int Size() const = 0;
	virtual NetworkItem* clone() const = 0;
	
	

};
#endif