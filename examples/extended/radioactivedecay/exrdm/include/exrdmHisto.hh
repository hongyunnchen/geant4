//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//

#ifndef exrdmHisto_h
#define exrdmHisto_h 1

//---------------------------------------------------------------------------
//
// ClassName:   exrdmHisto
//
// Description: Utility class to hold and manipulate histograms/nTuples
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#include "globals.hh"
#include <vector>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class exrdmHistoMessenger;

#ifdef G4ANALYSIS_USE_AIDA
namespace AIDA {
 class ITree;
 class ITuple;
 class IHistogram1D;
}
#endif

#ifdef G4ANALYSIS_USE_ROOT
class TFile;
class TH1D;
class TNtuple;
#endif


class exrdmHisto
{

public:
  exrdmHisto();

  ~exrdmHisto();

  void book();
  // Book predefined histogramms 

  void save();
  // Save histogramms to file

  void add1D(const G4String&, const G4String&, G4int nb=100, G4double x1=0., 
                                               G4double x2=1., G4double u=1.);
  // In this method histogramms are predefined

  void setHisto1D(G4int, G4int, G4double, G4double, G4double);
  // It change bins and boundaries

  void fillHisto(G4int, G4double, G4double);
  // exrdmHistogramms are filled

  void scaleHisto(G4int, G4double);

  void addTuple(const G4String&, const G4String&, const G4String&);
  // In this method nTuple is booked

  void fillTuple(G4int, const G4String&, G4double);
  // Fill nTuple parameter with a double

  void fillTuple(G4int, G4int, G4double);
  // Fill nTuple at a given col with a double
  void fillTuple(G4int, const G4String&, G4String);
  // Fill nTuple parameter with a string

  void fillTuple(G4int, const G4String&, G4bool);
  // Fill nTuple parameter with a bool

  void addRow(G4int);
  // Save tuple event 

  void setFileName(const G4String&);

  void setFileType(const G4String&);
  const G4String& FileType() const;

private:

  G4String histName;
  G4String histType;

  G4int    nHisto;
  G4int    nTuple;
  G4int    verbose;
  G4int    defaultAct;

#ifdef G4ANALYSIS_USE_AIDA
  std::vector<AIDA::IHistogram1D*> histo;
  std::vector<AIDA::ITuple*>   ntup;
  AIDA::ITree*    tree;
#endif

#ifdef G4ANALYSIS_USE_ROOT
  TFile* hfileROOT; 
  std::vector<TH1D*> ROOThisto;
  std::vector<TNtuple*>   ROOTntup;
  std::vector< std::vector<float> > Rarray;
  std::vector<G4int> Rcol;
#endif

  exrdmHistoMessenger* messenger;

  std::vector<G4int>     active;
  std::vector<G4int>     bins;
  std::vector<G4double>  xmin;
  std::vector<G4double>  xmax;
  std::vector<G4double>  unit;
  std::vector<G4String>  ids;
  std::vector<G4String>  titles;
  std::vector<G4String>  tupleName;
  std::vector<G4String>  tupleId;
  std::vector<G4String>  tupleList;
  std::vector<G4String>  tupleListROOT; 
};

#endif