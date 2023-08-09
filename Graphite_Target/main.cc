// Main file of the Geant4 program

// Include Geant4 libraries
#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

// Include header files
#include "Construction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "ActionInitialization.hh"

int main(int argc, char** argv) {
    
    // Create the G4 RunManager instance: heart of Geant4
    G4RunManager* runManager = new G4RunManager;
    
    // set mandatory initialization classes
    runManager->SetUserInitialization(new MyDetectorConstruction);
    runManager->SetUserInitialization(new MyPhysicsList);
    runManager->SetUserInitialization(new MyActionInitialization);
    
    // Initialize Geant4 kernel i.e. construct detector, create physics processes...
    runManager->Initialize();
    
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    
    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();
    
    // Get the pointer to the UI manager, which is a class automatically created when the G4RunManager is created
    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
    UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate");
    
    ui->SessionStart();
    
    delete runManager;
    delete visManager;
}
