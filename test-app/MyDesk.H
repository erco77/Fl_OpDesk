#ifndef _MY_DESK_H
#define _MY_DESK_H

//INSERT-LGPL-HEADER-HERE//

#include <FL/fl_ask.H>
#include "everything.H"
#include "MyButton.H"
#include "MyBox.H"

// CUSTOM Fl_OpDesk
//    Our app derives from the Fl_OpDesk widget to augment it with our app-specific code.
//
class MyDesk : public Fl_OpDesk {
    int next_boxid;			// next box id#

    // Fl_OpDesk calls this virtual when connection errors occur.
    //    Let's post a dialog instead of the default stderr behavior.
    //
    void ConnectionError(Fl_OpButton *src, Fl_OpButton *dst, std::string &errmsg);

public:
    MyDesk(int X,int Y,int W,int H,const char *L=0):Fl_OpDesk(X,Y,W,H,L) {
        next_boxid = 0;
    }

    // CLEAR THE DESK
    //    Resets our box id counter to zero
    //
    void Clear() {
	Fl_OpDesk::Clear();
        next_boxid = 0;
    }

    int GetNextBoxId() {
        return(++next_boxid);
    }

    int SaveLayout(FILE *fp);
    int LoadLayout(FILE *fp, int &line, std::string &errmsg);
    int CopySelected();
    int PasteSelected();
};

#endif /*_MY_DESK_H*/
