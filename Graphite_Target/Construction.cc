#include "Construction.hh"

/* 
The construction of a volume happens in 3 steps:
1) define a solid (ex. G4Box, G4Tubs...) which is just a shape
2) define the material (G4Material) and the logicalVolume
3) define the physical volume with G4PVPlacement

*/
MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume* MyDetectorConstruction::Construct()
{
    // Geant4 material manager
    G4NistManager* nist = G4NistManager::Instance();
    
    // Dimensions of the world mother volume
    G4double xWorld = 1.0*m;
    G4double yWorld = 1.0*m;
    G4double zWorld = 5*m;
    
    // World solid volume
    G4Box* solidWorld = new G4Box("World", xWorld, yWorld, zWorld);
    
    // G4_Galactic is a standard Geant4 material which has very low density (1e-25 g/cm2) and can be used to simulate the vacuum
    G4Material* worldMat = nist->FindOrBuildMaterial("G4_Galactic");
    
    // Logical volume of the world: comprises the material
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
    
    // World Physical volume
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);
    
    // Graphite target
    G4Box* target = new G4Box("target", 5*cm, 5*cm, 10*cm);
    G4Material* graphite = nist->FindOrBuildMaterial("G4_GRAPHITE");
    G4LogicalVolume* logicTarget = new G4LogicalVolume(target, graphite, "logicTarget");
    G4VPhysicalVolume* physTarget = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicTarget, "physTarget", logicWorld, false, 0, true);
    
    return physWorld;
}
