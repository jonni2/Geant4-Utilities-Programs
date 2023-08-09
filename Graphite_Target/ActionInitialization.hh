#ifndef ACTIONINITIALIZATION_H
#define ACTIONINITIALIZATION_H

/*
This file is responsible for the user initialization of the physical events 
 
The class musth inherit from G4VUserActionInitialization
*/

#include "G4VUserActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"

class MyActionInitialization : public G4VUserActionInitialization {
public:
    MyActionInitialization();
    ~MyActionInitialization();
    
    virtual void Build() const;
};

#endif
