//INSERT-LGPL-HEADER-HERE//

#include <stdio.h>
#include <string.h>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>

// Test the Fl_OpDesk widget

#include "Fl_OpDesk.H"
#include "Fl_OpBox.H"
#include "Fl_OpButton.H"

int main() {
    Fl_Double_Window *win = new Fl_Double_Window(720,486);
    Fl_Scroll *scroll = new Fl_Scroll(10,10,win->w()-20,win->h()-20);
    scroll->box(FL_DOWN_BOX);
    {
	const int deskw = 15000;
	const int deskh = 15000;
	Fl_OpDesk *opdesk = new Fl_OpDesk(0,0,deskw,deskh);
	opdesk->begin();
	{
	    printf("Creating %d boxes\n", (deskw/200)*(deskh/200));
	    for ( int x=30; x<deskw; x+=200 ) {
		for ( int y=30; y<deskh; y+=200 ) {
		    char s[80];
		    sprintf(s,"Box %d/%d",x,y);
		    Fl_OpBox *opbox = new Fl_OpBox(x,y,180,120,strdup(s));
		    opbox->begin();
		    {
		        /*Fl_OpButton *a =*/ new Fl_OpButton("A", FL_OP_INPUT_BUTTON);
		        /*Fl_OpButton *b =*/ new Fl_OpButton("B", FL_OP_INPUT_BUTTON);
		        /*Fl_OpButton *c =*/ new Fl_OpButton("CCC", FL_OP_INPUT_BUTTON);
		        /*Fl_OpButton *d =*/ new Fl_OpButton("OUT1", FL_OP_OUTPUT_BUTTON);
		        /*Fl_OpButton *e =*/ new Fl_OpButton("OUT2", FL_OP_OUTPUT_BUTTON);
		    }
		    opbox->end();
		}
	    }
	}
	opdesk->end();
    }
    scroll->end();
    win->resizable(win);
    win->show();
    return(Fl::run());
}
