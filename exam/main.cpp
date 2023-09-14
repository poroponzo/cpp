#include "IP.h"
#include "NetworkItem.h"
#include "PC.h"

int main() {
    IP a;
    a.print();

    IP b(192,168,1,201);
    b.print();

    PC nn;
    nn.Print();

    std::string pluto = "plutone";
    PC mm(pluto, a, 3);
    mm.Print();
    std::cout << "The ammount of allocated memory is: "<< mm.Size() << " bytes" << std::endl;

    std::cout << " ora testo il costruttore di copia" << std::endl;
    std::cout << " lo richiamo implicitamente quando inzializzo una variabile con un PC:"<< std::endl;
    
    PC originalPC;
    
    std::cout << "printo pc originale" << std::endl;
    originalPC.Print();

    std::cout << "copio, e printo la copia" << std::endl;
    PC copiedPC = originalPC;
    copiedPC.Print();



}


