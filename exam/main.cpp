#include "IP.h"
#include "NetworkItem.h"
#include "PC.h"

int main() {
    IP a;
    a.print();

    IP b(192,168,1,1);
    b.print();

    PC nn;
    nn.Print();

    std::string pluto = "plutone";
    PC mm(pluto, a, 3);
    mm.Print();
    std::cout << "The ammount of allocated memory is: "<< mm.Size() << " bytes" << std::endl;

    NetworkItem* clonedItem = mm.clone();

    // Verifica del comportamento del clone
    // Esempio: stampa il nome dell'oggetto clonato
    std::cout << "Cloned Item says: " << std::endl;
    mm.Print();


}


