/***************************************************************
 * Name:      wxsertermMain.h
 * Purpose:   Defines Application Frame
 * Author:    Achmadi (mekatronik.achmadi@gmail.com)
 * Created:   2021-02-13
 * Copyright: Achmadi ()
 * License:
 **************************************************************/

#ifndef WXSERTERMMAIN_H
#define WXSERTERMMAIN_H


#include "wx/aboutdlg.h"
#include "wxsertermApp.h"


#include "GUIFrame.h"

class wxsertermFrame: public GUIFrame
{
    public:
        wxsertermFrame(wxFrame *frame);
        ~wxsertermFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};

#endif // WXSERTERMMAIN_H
