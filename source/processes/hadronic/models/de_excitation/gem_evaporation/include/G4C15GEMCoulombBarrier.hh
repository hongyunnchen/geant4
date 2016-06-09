//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: G4C15GEMCoulombBarrier.hh,v 1.3 2006/06/29 20:15:23 gunter Exp $
// GEANT4 tag $Name: geant4-08-02 $
//
// Hadronic Process: Nuclear De-excitations
// by V. Lara (Dec 1999)

#ifndef G4C15GEMCoulombBarrier_h
#define G4C15GEMCoulombBarrier_h 1

#include "G4GEMCoulombBarrierHE.hh"
#include "globals.hh"

class G4C15GEMCoulombBarrier : public G4GEMCoulombBarrierHE
{
public:
  G4C15GEMCoulombBarrier() : G4GEMCoulombBarrierHE(15,6) {};
  ~G4C15GEMCoulombBarrier() {};

private:
  G4C15GEMCoulombBarrier(const G4C15GEMCoulombBarrier & right);

  const G4C15GEMCoulombBarrier & operator=(const G4C15GEMCoulombBarrier & right);
  G4bool operator==(const G4C15GEMCoulombBarrier & right) const;
  G4bool operator!=(const G4C15GEMCoulombBarrier & right) const;
  

};

#endif