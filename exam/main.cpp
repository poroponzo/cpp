#include "IP.h"
#include "NetworkItem.h"
#include "PC.h"
#include "Net.h"

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

    std::cout << "provo a creare una net default e a tirare il print" << std::endl;
    Net rete;
    rete.Print();

    std::cout << "ora provo ad aggiungere 1 PC e a tirare il print" << std::endl;
    std::cout << "mi aspetto printi gli IP forniti (rimanenti) e gli itemname" << std::endl;
    // devo unsare &pcname perché i metodi add e addcopy accettano un puntatore ad un oggetto di quella classe
    rete.Add(&nn);
    rete.Print();
    
    rete.Add(&mm);
    rete.Print();

    std::cout<<"ho invocato il metodo addcopy di rete su gibbone, poi printo:" << std::endl;
    std::cout<<"NB: gibbone è già un clone di mm" << std::endl;
    rete.AddCopy(&gibbone);
    rete.Print();
}


