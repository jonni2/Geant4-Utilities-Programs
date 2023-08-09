#include "PrimaryGeneratorAction.hh"

// Here we define the primary event in our simulation
MyPrimaryGeneratorAction::MyPrimaryGeneratorAction() {
    
    // 1 is the number of particles generated
    fParticleGun = new G4ParticleGun(1);
    
    // Table of particles allowed in Geant4
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    
    // Proton
    G4ParticleDefinition* particle = particleTable->FindParticle("proton");
    
    // Kinematics
    G4ThreeVector pos(0.*m, 0.*m, -5.*m); // Position where particle is generated
    G4ThreeVector mom(0., 0., 1.); // Momentum direction
    
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleEnergy(100*GeV); // Kinetic Energy
    
}

MyPrimaryGeneratorAction::~MyPrimaryGeneratorAction() {
    // fParticleGun must be DESTROYED in the destructor!!!
    delete fParticleGun;
}

void MyPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    
    fParticleGun->GeneratePrimaryVertex(anEvent);
}
