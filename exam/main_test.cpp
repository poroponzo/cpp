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
std::cout << "\n" <<  std::endl;
std::cout << "Now test the Net class:"<<  std::endl;
std::cout << "A default Net is built, and print method is called:"<<  std::endl;
Net net0;
net0.Print();
net0.Add(&pc0);
std::cout<< "Now the net add the pc0 \nCheck that content is changed:" << std::endl;
net0.Print();
std::cout <<"\n\n"<< std::endl;
std::cout <<"A new net called solarsystem is initialized \na IP and a list of available IP is passed"<< std::endl;
IP solar_ip(255,255,255,255);
// available IP list construction
std::list<IP> ipavailable({}); 
for (int i=0;  i<5; i++){
IP tempip(255,255,1,i);
ipavailable.push_back(tempip);
};
Net SolarSystem("Sun", solar_ip, ipavailable);
SolarSystem.Print();
std::cout <<"Try to add to the net pc1, pc2 and pc3"<< std::endl;
SolarSystem.Add(&pc1);
SolarSystem.Add(&pc2);
SolarSystem.Add(&pc3);
SolarSystem.Print();
std::cout <<"Add a copy of pc0, then print pc0 and the net"<< std::endl;
SolarSystem.AddCopy(&pc0);
SolarSystem.Print();
int size = SolarSystem.Size();
std::cout << "print the size of the net" << std::endl;
std::cout << "net size:" + std::to_string(size)+ " Bytes"<< std::endl;
std::cout <<"\n"<< std::endl;
std::cout <<"remove an element using the ip: 255.255.3:"<< std::endl;
IP iptoremove(255,255,1,3);
SolarSystem.remove(iptoremove);
SolarSystem.Print();
/* Ottengo questo errore: 
 I have written 5 IP and then print the first:
192.198.2.0
Create a default PC and print it:
terminate called after throwing an instance of 'std::bad_array_new_length'
  what():  std::bad_array_new_length
fish: Job 1, './prova' terminated by signal SIGABRT (Abort)
Però se lo ricompilo tot volte e lo lencio tot volte poi va
*/
std::cout <<"creo una lista di puntatori a networkitem contenete 2 PC, una networkitem generica e una net"<< std::endl;
std::cout <<"invoco il metodo print scorrendo la lista con un for e testo il polimorfismo:" << std::endl;
PC it;
std::list<NetworkItem*> itemlist ={&pc4,&pc5, &it , &SolarSystem};
for(NetworkItem* item : itemlist){
	item->Print();
}

}
