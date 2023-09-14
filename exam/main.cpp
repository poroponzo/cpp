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

    mm.clone();
    //gg.Print();

    // Verifica del comportamento del clone
    // Esempio: stampa il nome dell'oggetto clonato
    //std::cout << "Cloned Item says: " << std::endl;
    //*clonedItem.Print();

    // Creazione di una copia dell'oggetto originale utilizzando il costruttore di copie
    std::cout << "Copied Item says: " << std::endl;
    PC pippo(mm);
    pippo.Print();

    // richiamo il costruttore di copie inizializzando una nuova variabile con un oggetto della classe PC
    std::cout << "Copied2 Item says: " << std::endl;
    PC gibbone = mm;
    gibbone.Print();



    
}


