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

// alternative constructor che non worka
PC(std::string, IP, int);

//print identificatore e ip
void Print() const override;

// print del size
int Size() const;

// cloning and referring to Networkitem
NetworkItem* clone() const;

// default destructor
~PC(); 



//size mi deve dare mem
};

#endif
