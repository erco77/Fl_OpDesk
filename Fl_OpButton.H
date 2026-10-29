#ifndef _FL_OPBUTTON_H_
#define _FL_OPBUTTON_H_

//INSERT-LGPL-HEADER-HERE//

///
/// \file
/// \brief This file contains the definitions for the Fl_OpButton widget.
///

#include <vector>
#include <string>

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>

#include "Fl_OpBox.H"

class Fl_OpDesk;
class Fl_OpBox;
class Fl_OpConnect;

/// \enum Fl_OpButtonType
/// The types of buttons: input or output.
///
enum Fl_OpButtonType {
    FL_OP_INPUT_BUTTON,		///< -- an input button
    FL_OP_OUTPUT_BUTTON,	///< -- an output button
};

/// \class Fl_OpButton
///
/// \brief The Fl_OpButton widget, an FLTK widget derived from Fl_Button
///        that represents an input or output port of an Fl_OpBox. Ports become
///        children of the Fl_OpBox in the usual FLTK fashion, where
///        opbox->begin() and opbox->end() are used to bracket the
///        creation of buttons, a simple example being:
/// \code
///         // Create box
///         Fl_OpBox *box = new Fl_OpBox(X,Y,150,80,"add");
///         box->copy_label("add");
///         box->begin();
///             // Create two input buttons ("A", "B") and one output button ("OUT")
///             Fl_OpButton *a   = new Fl_OpButton("A", FL_OP_INPUT_BUTTON);
///             Fl_OpButton *b   = new Fl_OpButton("B", FL_OP_INPUT_BUTTON);
///             Fl_OpButton *out = new Fl_OpButton("OUT", FL_OP_OUTPUT_BUTTON);
///         box->end();
/// \endcode
///
/// Connection validation and notification methods.
///
///    The virtual Connecting() and Disconnecting() methods handle connection
///    validation and notification. These are separate from Fl_Button's click
///    callback; they do not take userdata or a connection-type argument.
///
///    WHEN A CONNECTION IS BEING MADE
///
///    Connecting() is called on each endpoint in turn. The second endpoint
///    is checked only if the first endpoint accepts the connection.
///
///    On input:
///
///       button   -- the opposing button
///       errmsg   -- a reference to an error message; set this if rejecting
///                   the connection
///
///    On return:
///
///       Return 0 to allow the connection, or -1 to reject it with errmsg
///       set to the reason. The implementation treats any negative return
///       value as rejection.
///
///    WHEN A CONNECTION IS BEING REMOVED
///
///    Disconnecting() is called on the endpoints when they are disconnected.
///    It can also be called when a partially established connection is
///    rolled back after validation fails.
///
///    On input:
///
///       button   -- the opposing button being disconnected
///
///    On return:
///
///       No return value; Disconnecting() returns void.
///
class Fl_OpButton;

// Operation Buttons
//    Represents an input or output button belonging to an Fl_OpBox.
//
class Fl_OpButton : public Fl_Button {
    Fl_OpButtonType           button_type;	// type of this button (input|output)
    std::vector<Fl_OpButton*> connected_to;	// array of button(s) we're connected to
    int                       dragging;		// used for connection dragging

    // PRIVATE METHODS
    friend class Fl_OpDesk;
    void _RemoveConnect(Fl_OpButton *but);
    int  _ConnectToOnly(Fl_OpButton *but, std::string &errmsg);
    void _DisconnectOnly(Fl_OpButton *but);

public:
    // CTORS
    Fl_OpButton(const char *L, Fl_OpButtonType io);
    ~Fl_OpButton();
    Fl_OpButton(const Fl_OpButton&);

    // FLTK
    void draw();
    int handle(int e);

    // MISC
    Fl_OpButtonType GetButtonType() const;
    int GetMinimumHeight() const;
    int GetMinimumWidth() const;
    std::string GetFullName() const;

    // PARENT ACCESS
    Fl_OpBox *GetOpBox();
    const Fl_OpBox* GetOpBox() const;
    Fl_OpDesk *GetOpDesk();
    const Fl_OpDesk* GetOpDesk() const;

    // CONNECTIONS
    int IsConnected() const;
    int IsConnected(const Fl_OpButton *but) const;
    int ConnectTo(Fl_OpButton *but, std::string &errmsg);
    void Disconnect(Fl_OpButton *but);
    void DisconnectAll();

    Fl_OpButton* GetConnectedButton(size_t index=0);
    const Fl_OpButton* GetConnectedButton(size_t index=0) const;
    size_t GetTotalConnectedButtons() const;
    void GetOutputBoxes(std::vector<Fl_OpBox*> &outboxes);
    Fl_OpConnect* GetConnection(size_t index);

    // VIRTUALS

    /// Override this method to validate a connection to the opposing button.
    ///
    /// The app can 'OK' the connection by returning 0,
    /// or 'FAIL' the connection by returning -1 and setting \p errmsg to the reason why.
    ///
    /// Example:
    /// \code
    /// class MyButton : public Fl_OpButton {
    ///     // Handle checking connections
    ///     int Connecting(Fl_OpButton *to, std::string &errmsg) {
    ///         if ( to->GetButtonType() != GetButtonType() ) {
    ///             return(0);      // OK
    ///         } else {
    ///             errmsg = "It's not OK to connect";
    ///             return(-1);     // FAIL
    ///         }
    ///     }
    /// [..]
    /// \endcode
    ///
    ///
    virtual int Connecting(Fl_OpButton*, std::string& errmsg) {
        return(0);
    }

    /// This virtual method can be defined by the app to detect when connections are being deleted.
    virtual void Disconnecting(Fl_OpButton*) {
        return;
    }

};
#endif /* _FL_OPBUTTON_H_ */
