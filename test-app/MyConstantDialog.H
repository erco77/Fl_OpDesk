#ifndef _MY_CONSTANT_DIALOG_H
#define _MY_CONSTANT_DIALOG_H

//INSERT-LGPL-HEADER-HERE//

#include "everything.H"

class MyButton;				// forward declare MyButton

//
// MyConstantDialog -- a popup dialog for prompting the user for a constant value
//
class MyConstantDialog : public Fl_Double_Window {
    MyButton *butt;			// owning button (not the FLTK parent)
    Fl_Input *input;			// input widget

    // Callback to handle user input
    void InputCallback2();
    static void InputCallback(Fl_Widget*, void *userdata) {
	MyConstantDialog *o = (MyConstantDialog*)userdata;
	o->InputCallback2();
    }

public:
    MyConstantDialog(MyButton *butt);	// CTOR
    void show();			// show the window, get current value from parent
};

#endif
