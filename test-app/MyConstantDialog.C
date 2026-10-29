#include <string>
#include "MyButton.H"		// our own button class derived from Fl_OpButton
#include "MyConstantDialog.H"

//INSERT-LGPL-HEADER-HERE//

// Callback to handle when user hits Enter.
//     Save current input value to button, and hide the dialog window.
//
void MyConstantDialog::InputCallback2() {
    butt->SetConstantValue(input->value());
    hide();
}

// CONSTRUCTOR
MyConstantDialog::MyConstantDialog(MyButton *butt) : Fl_Double_Window(250,50) {
    // Save the owning button for later use (it is not our FLTK parent).
    this->butt = butt;

    // Set title of window based on button's full name
    std::string title = butt->GetFullName();
    copy_label(title.c_str());

    // Create input widget, assign it the button's current input value.
    begin();
	input = new Fl_Input(60,10,180,25,"Value:");	// create input widget
	input->callback(InputCallback, (void*)this);	// callback for input widget
	input->when(FL_WHEN_ENTER_KEY_ALWAYS);		// do callback when user hits enter
    end();

    // Make this dialog window modal (above all others)
    set_modal();
    show();
}

// Show the dialog, update constant value with button's current value
void MyConstantDialog::show() {
    std::string const_value = butt->GetConstantValue();
    input->value(const_value.c_str());
    // Select all text, using the renamed API on FLTK 1.4 and later.
#if FL_API_VERSION >= 10400
    input->insert_position(0,input->size());
#else
    input->position(0,input->size());
#endif
    position(Fl::event_x_root()-10, Fl::event_y_root()-20);	// position window near mouse
    Fl_Double_Window::show();
}

