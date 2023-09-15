#ifndef IP_H
#define IP_H

#include <iostream>
using namespace std;

class IP {
	int ip[4];

public:
	
		IP(int a=0, int b= 0, int c = 0, int d = 0) {
		ip[0] = a;
		ip[1] = b;
		ip[2] = c;
		ip[3] = d;
	}

	~IP() {}

	IP(const IP& other) {
		ip[0] = other.ip[0];
		ip[1] = other.ip[1];
		ip[2] = other.ip[2];
		ip[3] = other.ip[3];
	}

	void set_ip(int pos, int value) {
		ip[pos - 1] = value;
	}

	void get_ip(int pos) const {
		cout << ip[pos - 1] << endl;
	}

	void Print() const{
		cout << "IP adress is" << " "<< ip[0] << "." << ip[1] << "." << ip[2] << "." << ip[3] << endl;
	}

	bool operator==(const IP& other) const {
		return (ip[0] == other.ip[0] && ip[1] == other.ip[1] && ip[2] == other.ip[2] && ip[3] == other.ip[3]);
	}
	
	
};

#endif
