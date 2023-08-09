#ifndef PHYSICSLIST_HH
#define PHYSICSLIST_HH

/* The PhysicsList file is responsible for the inclusion of the required physical processes that we want to use in our simulation.

The class must inherit from G4VUserPhysicsList or G4VModularPhysicsList

*/

// These are some of the physical libraries we can include
#include "G4VUserPhysicsList.hh"
#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4HadronPhysicsFTFP_BERT_TRV.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4OpticalPhysics.hh"

// Can also: class MyPhysicsList : public G4VUserPhysicsList
class MyPhysicsList : public G4VModularPhysicsList {
public:
    
    MyPhysicsList();
    ~MyPhysicsList();
    
};

#endif
