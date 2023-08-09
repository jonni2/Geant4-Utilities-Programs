#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

// This file (together with Construction.cc) are responsible for creating the geometry and materials of the simulation world
// The class must inherit from G4VUserDetectorConstruction

// Include Geant4 libraries
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"

// Class called in main() to construct the whole world, detectors and shapes
class MyDetectorConstruction : public G4VUserDetectorConstruction {
public:
    MyDetectorConstruction();
    ~MyDetectorConstruction();
    
    virtual G4VPhysicalVolume* Construct();
    
private:
    
};

#endif
