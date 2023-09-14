#ifndef PC_H
#define PC_H
#include <iostream>
#include "NetworkItem.h"

// eredita attributi pubblici di NetworkItem
class PC : public NetworkItem{
int *mem;
int memsize;

public:
// default costructor
PC(); 

// alternative constructor 
PC(std::string, IP, int);

//copy constructor
PC(const PC& other);

//print identificatore e ip
void Print() const override;

// print del size
int Size() const;

// metodo per settare memoria
PC& SetMemory(int *memory, int size);

// cloning and referring to Networkitem
NetworkItem* clone() const;

// default destructor
~PC(); 



//size mi deve dare mem
};

#endif
