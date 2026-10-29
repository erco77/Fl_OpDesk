#ifndef _EVERYTHING_H
#define _EVERYTHING_H

//INSERT-LGPL-HEADER-HERE//

// OS
#include <string>		// STL string class
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#ifdef MICROSOFT
// Grr...
#define snprintf _snprintf
#endif /*MICROSOFT*/

// FLTK
#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>
#include <FL/fl_ask.H>		// fl_choice()
#include <FL/Fl_Input.H>

// Fl_OpDesk WIDGETS
#include <Fl_OpDesk.H>
#include <Fl_OpBox.H>
#include <Fl_OpButton.H>

// MISC
#include "Subs.H"

#endif

