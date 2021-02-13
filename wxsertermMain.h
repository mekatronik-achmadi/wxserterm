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
#include "wx/timer.h"
#include "wxsertermApp.h"


#include "GUIFrame.h"
#include "ceSerial.h"

class wxsertermFrame: public GUIFrame
{
    public:
        wxsertermFrame(wxFrame *frame);
        ~wxsertermFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);

        // override from GUIFrame
        virtual void onPortChoice( wxCommandEvent& event );
		virtual void onBaudChoice( wxCommandEvent& event );
		virtual void onBtnPortOpen( wxCommandEvent& event );
		virtual void onTxtSendEnter( wxCommandEvent& event );

        // non-wizard functions
        virtual void onCharReceive(char ch);
        virtual void addListPort(void);
        virtual void addListBaud(void);
        virtual void closingPort(void);
        virtual void defaultPort(void);
        virtual void onTimerTick(wxTimerEvent& event);
        virtual char* wxstr2char(wxString& Text);

        //non-wizard variables
        ce::ceSerial *serComm;
        wxString devPort;
        long devBaud;
        bool ignoreLF;
        wxTimer *serTimer;
        wxString serReq;
};

#endif // WXSERTERMMAIN_H
