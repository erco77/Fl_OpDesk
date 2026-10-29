#ifndef _MY_BOX_H
#define _MY_BOX_H

//INSERT-LGPL-HEADER-HERE//

#include "everything.H"

// APP'S INCLUDE FILES
#include "MyButton.H"
#include "MyBoxInfoDialog.H"

// CUSTOM Fl_OpBox
//    Our app derives from the Fl_OpBox widget to augment it with our app-specific code.
//
class MyBox : public Fl_OpBox {
    std::string name;			// name for this box, eg. "add"
    std::string srccode;		// source code for this box
    int traversed;			// "traversed" flag -- used by code generator
    MyBoxInfoDialog *infodialog;	// info dialog for this box

    static void _ExpandVariable(std::string& src, const std::string varname, const std::string value);

    int _LayoutMakeButton(const std::string &buttname, Fl_OpButtonType io,
                          FILE *fp, int &line, std::string &errmsg);
    int _LoadSrc(FILE *fp, int &line, std::string &errmsg);

public:
    // CTOR
    MyBox(int X,int Y,int W,int H,const char *L=0) : Fl_OpBox(X,Y,W,H,L) {
        name = std::string(L ? L : "unknown");
        AssignUniqueFullName();
	infodialog = new MyBoxInfoDialog();
    }
    MyBox(const MyBox& o);
    void CopyButtons(const MyBox& o);

    // SOURCE CODE
    void SetSourceCode(const char *val);
    std::string GetSourceCode();
    std::string GetExpandedSourceCode();

    // BUILD CODE TRAVERSAL
    int GetTraversed() const;
    int IsTraversed() const;
    void SetTraversed(int val);

    // LAYOUT LOAD/SAVE
    int LoadLayout(FILE *fp, int &line, std::string &errmsg);
    int SaveLayout(FILE *fp);

    // NAME
    void AssignUniqueFullName();
    void SetName(const char *newname);
    std::string GetName() const;

    // BOX INFO DIALOG
    void ShowInfoDialog();

    // FLTK
    int handle(int e);
};

#endif
