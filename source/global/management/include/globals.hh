// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: globals.hh,v 2.6 1998/09/24 01:06:22 gcosmo Exp $
// GEANT4 tag $Name: geant4-00 $
//
//
// Global Constants and typedefs
//
// History:
// 30.06.95 P.Kent - Created
// 16.02.96 G.Cosmo - Added inclusion of "templates.hh"
// 03.03.96 M.Maire - Added inclusion of "G4PhysicalConstants.hh"
// 08.11.96 G.Cosmo - Added cbrt() definition and G4ApplicationState enum type
// 29.11.96 G.Cosmo - Added typedef of HepBoolean to G4bool
// 22.10.97 M.Maire - Moved PhysicalConstants at the end of the file
// 04.12.97 G.Cosmo,E.Tcherniaev - Migrated to CLHEP
// 05.06.98 M.Maire - temporary (for alpha07) restore G4 system of units 
// 26.08.98 J.Allison,E.Tcherniaev - introduced min/max/sqr/abs functions
// 22.09.98 G.Cosmo - removed min/max/sqr/abs functions and replaced with
//                    inclusion of CLHEP/config/TemplateFunctions.h for CLHEP-1.3

#ifndef GLOBALS_HH
#define GLOBALS_HH

#include "G4ios.hh"

// Undefine possible existing min/max/sqr/abs macros first
// (temporary solution)
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif
#ifdef sqr
#undef sqr
#endif
#ifdef abs
#undef abs
#endif

// Includes also CLHEP.h with typedef for numeric types and
// implicit inclusions of <stdlib.h>, <limits.h>, <math.h>.
#include <CLHEP/config/TemplateFunctions.h>

// Typedefs to decouple from library classes
#include <rw/cstring.h>
typedef RWCString G4String;

// Typedefs for numeric types
// [NOTE: Will in future need to be made more sophisticated]
typedef HepDouble G4double;
typedef HepFloat G4float;
typedef HepInt G4int;
#ifdef G4_HAVE_BOOL
  typedef bool G4bool;
#else
  typedef HepBoolean G4bool;
#endif
typedef long G4long;

// Includes some additional definitions
#include "templates.hh"

// cbrt() function - define G4_NO_CBRT if the function is not available
#ifdef G4_NO_CBRT
static double cbrt(double x) { return pow(x,1./3.); }
#endif

// System of Units and Physical Constants
////#include <CLHEP/Units/PhysicalConstants.h>
#include "PhysicalConstants.h"

// Global error function
void G4Exception(const char* s=0);

#endif /* GLOBALS_HH */




