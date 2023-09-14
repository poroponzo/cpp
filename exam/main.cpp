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

    // v è il vettore di memoria che voglio assegnare
    // size è la grandezza della memoria che voglio allocare -> deve essere uguale o minore di memsize, sennò da errore
    std::string pluto = "plutone";
    PC mm(pluto, a, 2);
    int v[3] = {1, 2, 3};
    mm.SetMemory(v, 3);
    mm.Print();
    std::cout << "The ammount of allocated memory is: "<< mm.Size() << " bytes" << std::endl;

    NetworkItem* clonedItem = mm.clone();

    // Verifica del comportamento del clone
    // Esempio: stampa il nome dell'oggetto clonato
    std::cout << "Cloned Item says: " << std::endl;

    // Creazione di una copia dell'oggetto originale utilizzando il costruttore di copie
    PC pippo(mm);

    pippo.Print();
}


