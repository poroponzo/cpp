#include "Net.h"
#include "IP.h"
#include "PC.h"
#include "NetworkItem.h"
#include <iostream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	Net root("root", IP(10, 1, 3, 1));
	PC* pc = new PC("pc", IP());
	root.Add(pc);

	Net* nodo1 = new Net("node1", IP(10, 1, 3, 2));
	for (int i = 0; i < 1; i++) { //we can change i value but i=1 for semplicity 
		PC* pc = new PC("pc1", IP(0, 0, 0, 1));
		nodo1->Add(pc);
	}

	Net* nodo2 = new Net("node2", IP(10, 1, 3, 3));
	for (int i = 0; i < 1; i++) {
		PC* pc = new PC("pc2", IP(0, 0, 0, 2));
		nodo2->Add(pc);
	}

	nodo1->AddCopy(nodo2);
	root.Add(nodo1);
	root.AddCopy(nodo2);
	root.Add(nodo2);
	cout << "Network state:" << "\n";
	root.Print();
	cout << "Net size = " << root.Size() << '\n' << endl;

	root.remove(IP(10, 1, 3, 2));//where w.x.y.z is the address of the NetworkItem to be removed
	cout << "Network state after removing Net with IP 10.1.3.2:" << "\n";
	root.Print();
	cout << "Net size = " << root.Size() << endl;

	return 0;
}

/*
example for IP class

#include "IP.h"
#include <iostream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main() {
	IP ip1(192, 168, 0, 1);
	IP ip2(192, 168, 0, 2);
	IP ip3(ip1);
	ip1.Print();
	ip2.Print();
	ip3.Print();



	if (ip1 == ip2) {
		cout << "ip1 and ip2 are equal" << endl;
	}
	else {
		cout << "ip1 and ip2 are not equal" << endl;
	}

	if (ip1 == ip3) {
		cout << "ip1 and ip3 are equal" << endl;
	}
	else {
		cout << "ip1 and ip3 are not equal" << endl;
	}

	return 0;
}

*/



/*
example for PC class
#include "PC.h"
#include <iostream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main() {
	PC my_pc("MyPC", IP(192, 168, 0, 1));

	my_pc.Print(); // prints "Item name: MyPC, IP address: 192.168.1.1"
	cout << "Memory size: " << my_pc.Size() <<endl; // prints "Memory size: 1024"


	return 0;

	}
*/



