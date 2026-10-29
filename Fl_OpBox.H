#ifndef _FL_OPBOX_H_
#define _FL_OPBOX_H_

//INSERT-LGPL-HEADER-HERE//

///
/// \file
/// \brief This file contains the definitions for the Fl_OpBox widget.
///

#include <FL/Fl_Group.H>

#include <string>

#include "Fl_OpButton.H"

class Fl_OpButton;
class Fl_OpDesk;

/// \class Fl_OpBox
///
/// \brief The Fl_OpBox widget, an FLTK widget derived from Fl_Group
///        that manages the box itself and any Fl_OpButtons it may have.
///
/// \code
///
///    . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
///    .                                                           .
///    .                   ______________________                  .
///    .                  |        title         |                 .
///    .                  |______________________|                 .
///    .                  |   |              |   |                 .
///    .   Fl_OpButton ---| A |              | C |--- Fl_OpButton  .
///    .                  |   |              |   |                 .
///    .                  |___|______________|___|                 .
///    .                              \                            .
///    .                            Fl_OpBox                       .
///    .                                                           .
///    . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
///
/// \endcode
///

class Fl_OpBox : public Fl_Group {
    int eventxy[2];			// used for dragging: last x/y event
    int dragging;			// used for dragging
    int min_buttw;			// minimum button width
    int min_boxh;			// minimum box height
    int inbutt_w;			// input button widths
    int outbutt_w;			// output button widths
    int min_conlen;			// minimum connector length
    int selected;			// 1=selected, 0=deselected
    std::vector<Fl_OpButton*> inputs;	// input buttons
    std::vector<Fl_OpButton*> outputs;	// output buttons
    Fl_OpDesk *opdesk;			// parent opdesk

protected:
    // These are used by Fl_OpButton ctors/dtors only
    friend class Fl_OpButton;
    void _AddInputButton(Fl_OpButton*);
    void _AddOutputButton(Fl_OpButton*);
    void _RemoveButton(Fl_OpButton*);
    void _RecalcButtonSizes();

public:
    // CTORS
    Fl_OpBox(int X,int Y,int W,int H,const char*L);
    ~Fl_OpBox();
    Fl_OpBox(const Fl_OpBox& o);

    /// Return the height of the title bar.
    int GetTitleHeight() const {
        return(labelsize() + 6);
    }

    // FLTK
    int handle(int);
    void draw();

    // MINIMUM BUTTON/BOX HEIGHT

    /// Set minimum button width.
    void SetMinimumButtonWidth(int val) {
        min_buttw = val;
    }

    /// Get minimum button width.
    int GetMinimumButtonWidth() const {
        return(min_buttw);
    }

    /// Set minimum box height.
    void SetMinimumBoxHeight(int val) {
        min_boxh = val;
    }

    /// Get minimum box height.
    int GetMinimumBoxHeight() const {
        return(min_boxh);
    }

    /// Set the minimum connector length.
    void SetMinimumConnectLength(int val) {
        min_conlen = val;
    }

    /// Get the minimum connector length.
    int GetMinimumConnectLength() const {
        return(min_conlen);
    }

    /// Get selection state for this box.
    int GetSelected() const {
       return(selected);
    }

    /// Set selection state for this box.
    void SetSelected(int val) {
       selected = val;
    }

    // INPUT BUTTON ACCESS
    int          GetTotalInputButtons() const;
    Fl_OpButton *GetInputButton(int index) const;
    int          GetIndexForInputButton(Fl_OpButton*) const;

    // OUTPUT BUTTON ACCESS
    int          GetTotalOutputButtons() const;
    Fl_OpButton *GetOutputButton(int index) const;
    int          GetIndexForOutputButton(Fl_OpButton*) const;

    // ALL BUTTON ACCESS
    int          GetTotalButtons() const;
    Fl_OpButton *GetButton(int index) const;
    int          GetIndexForButton(Fl_OpButton*) const;

    // MISC
    Fl_OpButton* FindButtonByLabel(const std::string& lname, std::string& errmsg);
    Fl_OpButton* FindButtonUnderMouse();
    int          FindButtonByPtr(Fl_OpButton *b) const;
    void BringToFront();
    void CopyButtons(const Fl_OpBox& o);

    // PARENT ACCESS
    Fl_OpDesk* GetOpDesk();
    const Fl_OpDesk* GetOpDesk() const;
};
#endif /* _FL_OPBOX_H_ */
