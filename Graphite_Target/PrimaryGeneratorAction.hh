#ifndef PRIMARYGENERATORACTION_HH
#define PRIMARYGENERATORACTION_HH

/*
This file is responsible for the generation of events in our simulation.

The class must inherit from G4VUserPrimaryGeneratorAction and must contain the method GeneratePrimaries
*/

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include "G4IonTable.hh"

class MyPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    MyPrimaryGeneratorAction();
    ~MyPrimaryGeneratorAction();
    
    virtual void GeneratePrimaries(G4Event*);    
private:
        
    // G4ParticleGun is of the abstract class G4VPrimaryGenerator, the others being G4GeneralParticleSource and G4HEPEvtInterface
    G4ParticleGun* fParticleGun;
    
};

#endif
