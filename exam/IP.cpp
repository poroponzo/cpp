#include <iostream>
#include "IP.h"


// Implementazione costruttore
IP::IP() {
        for (int i = 0; i < 4; i++) {
        ip[i] = std::rand() %256;
    }
}

IP::IP(int oct1, int oct2, int oct3, int oct4) {
    ip[0] = oct1;
    ip[1] = oct2;
    ip[2] = oct3;
    ip[3] = oct4;
}

// Implementazione del costruttore di copia
IP::IP(const IP& other) {
    for (int i = 0; i < 4; i++) {
        ip[i] = other.ip[i];
    }
}

// Metodo pubblico per ottenere un singolo ottetto dell'indirizzo IP
int IP::GetOctet(int index) const {
    if (index >= 0 && index < 4) {
        return ip[index];
    } else {
        // Includere la gestione degli errori se l'indice è fuori dai limiti
        return -1; // Esempio di gestione dell'errore
    }
}


// definisco operatore ==
bool IP::operator==(const IP& other) const {
    for (int i = 0; i < 4; i++) {
        if (ip[i] != other.ip[i]) {
            return false;
        }
    }
    return true;
}

//metodo print
void IP::print() const {
        std::cout << std::to_string(ip[0]) +
        '.'+std::to_string(ip[1])+
        '.'+std::to_string(ip[2])+
        '.'+std::to_string(ip[3])
        << std::endl;
}


IP::~IP() {
}



