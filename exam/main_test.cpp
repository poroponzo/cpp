#include "IP.h"
#include "NetworkItem.h"
#include "PC.h"
#include "Net.h"

int main() {

// produce some IP
std::cout << " I have written 5 IP and then print the first:" << std::endl;
IP a(192,198,2,0);
IP b(192,198,2,1);
IP c(192,198,2,2);
IP d(192,198,2,3);
IP e(192,198,2,4);
a.print();
std::cout << "Create a default PC and print it:" << std::endl;
PC pc0;
pc0.Print();

std::cout << "Create 5 PCs with planets name and addresses produced before:" << std::endl;
std::cout << "(The memory size is growing form pc1 to pc5)" << std::endl;
PC pc1("mercury",a, 1);
PC pc2("venus", b, 2);
PC pc3("jupiter", c, 3);
PC pc4("saturn", d, 4);
PC pc5("neptune", e, 5);

std::cout << "Print the third computer:" << std::endl;
pc3.Print();
std::cout << "The ammount of allocated memory is: "<< pc3.Size() << " bytes" << std::endl;
std::cout << "For a PC the default memory content is 0 (x memorysize) "<<  std::endl;
std::cout << "To set the memory content invoke the method setmemory"<<  std::endl;
std::cout << "setting value v[11, 22, 33] in the PC0 (default pc) and then print"<<  std::endl;

std::cout << "verify that memory content is changed"<<  std::endl;
int v[2] = {11,22};
pc0.SetMemory(v,2);
pc0.Print();

}