#ifndef _MY_BOX_INFO_DIALOG_H
#define _MY_BOX_INFO_DIALOG_H

//INSERT-LGPL-HEADER-HERE//

#include "everything.H"
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Pack.H>
#include "MyButton.H"
#include <vector>

// BUTTON INFO CLASS
//    Used by the MyBoxInfoDialog class (below) to handle a single button's
//    bookkeeping info as an input field with a prompt. ie:
//                      _____________________
//        Button Name: |_____________________|
//
class ButtonInfo : public Fl_Group {
    MyButton *but;
    std::string name;
    Fl_Input *input;

    // Handle user changing input field
    void InputChanged() {
	but->SetConstantValue(input->value());
	redraw();
    }
    // CALLBACK INVOKED WHEN USER CHANGES 'input'
    static void InputChanged_CB(Fl_Widget *w, void *data) {
        ((ButtonInfo*)data)->InputChanged();
    }
public:
    // Ctor
    ButtonInfo(int X,int Y,int W,int H, MyButton *but);
    // Set the name of the button
    void SetName(const char *val) {
	name = val;
	input->label(name.c_str());
    } 
    // Set the constant value for the button
    void SetConstantValue(const char *val) {
	input->value(val);
    }
    // Set the button's type
    void SetButtonType(Fl_OpButtonType type) {
	if ( type == FL_OP_OUTPUT_BUTTON ) {
	   input->deactivate();
	} else {
	   input->activate();
	}
    }
};

// BOX INFO DIALOG CLASS
//    A dialog window showing all a box's input and output buttons
//    names and values, eg:
//    _____________________________________________
//   |_Title_______________________________________|
//   |                  _____________________      |
//   |    Input Button |_____________________|     |  <-- for as many input buttons
//   |                  _____________________      |      as the box has
//   |    Input Button |_____________________|     |
//   |                  _____________________      |
//   |   Output Button |_____________________|     |  <-- for as many output buttons ""
//   |_____________________________________________|
//
class MyBoxInfoDialog : public Fl_Window {
    std::vector<ButtonInfo*> binfos;	// array of button info fields
    Fl_Scroll *scroll;			// make the dialog window scrollable
    Fl_Pack   *pack;			// use a 'pack' to manage the button info fields
public:
    // Ctor
    MyBoxInfoDialog() : Fl_Window(300,200) {
	// Create scroller
        scroll = new Fl_Scroll(10,10,w()-20,h()-20);
	scroll->begin();
	{
	    // Create a pack to handle the array of ButtonInfo's
	    pack = new Fl_Pack(scroll->x(), scroll->y(), scroll->w(), scroll->h());
	    pack->box(FL_NO_BOX);
	    pack->color(46);
	    pack->type(Fl_Pack::VERTICAL);
	    pack->spacing(3);
	}
	scroll->end();
	resizable(this);
    }
    // Add a button to the dialog
    void AddButton(MyButton *but) {
	pack->begin();
	{
	    int X = x();
	    int Y = y();	// Fl_Pack will override this
	    int W = scroll->w() - scroll->scrollbar.w();
	    int H = 20;
	    ButtonInfo *binfo = new ButtonInfo(X,Y,W,H,but);
	    binfos.push_back(binfo);
	}
	pack->end();
    }
    // Clear the dialog of all buttons
    void Clear() {
        pack->clear();		// dump all the button info instances
	binfos.clear();
    }
    // Show the dialog window
    void Show(const char *title) {
        copy_label(title);
	show();
    }
};

#endif
