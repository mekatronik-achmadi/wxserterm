/***************************************************************
 * Name:      wxsertermMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Achmadi (mekatronik.achmadi@gmail.com)
 * Created:   2021-02-13
 * Copyright: Achmadi ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxsertermMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


wxsertermFrame::wxsertermFrame(wxFrame *frame)
    : GUIFrame(frame)
{
    serComm = new ce::ceSerial();
    ignoreLF = true;

    addListPort();
    addListBaud();

    devPort = m_chPort->GetString(m_chPort->GetSelection());
    devBaud = wxAtol(m_chBaud->GetString(m_chBaud->GetSelection()));

    serTimer = new wxTimer();
    serTimer->Bind(wxEVT_TIMER, &wxsertermFrame::onTimerTick, this);

    m_btnPortOpen->SetLabel("Open Port");
    m_btnPortList->Enable(true);
    m_chPort->Enable(true);
    m_chBaud->Enable(true);
    statusBar->SetStatusText("Closed: "+ devPort +"-"+wxString::Format(wxT("%lu"),devBaud)+"-8N1N",0);
}

wxsertermFrame::~wxsertermFrame()
{
}

void wxsertermFrame::OnClose(wxCloseEvent &event)
{
    closingPort();
    Destroy();
}

void wxsertermFrame::OnQuit(wxCommandEvent &event)
{
    closingPort();
    Destroy();
}

void wxsertermFrame::addListPort(void){
#ifdef ceLINUX
    m_chPort->Append(_("/dev/ttyUSB0"));
	m_chPort->Append(_("/dev/ttyUSB1"));
	m_chPort->Append(_("/dev/ttyUSB2"));
	m_chPort->Append(_("/dev/ttyACM0"));
	m_chPort->Append(_("/dev/ttyACM1"));
	m_chPort->Append(_("/dev/ttyACM2"));
#else
    m_chPort->Append(_("\\\\.\\COM1"));
	m_chPort->Append(_("\\\\.\\COM2"));
	m_chPort->Append(_("\\\\.\\COM3"));
	m_chPort->Append(_("\\\\.\\COM4"));
	m_chPort->Append(_("\\\\.\\COM5"));
	m_chPort->Append(_("\\\\.\\COM6"));
#endif
    m_chPort->SetSelection(0);
}

void wxsertermFrame::addListBaud(void){
    m_chBaud->Append(_("4800"));
	m_chBaud->Append(_("9600"));
	m_chBaud->Append(_("38400"));
	m_chBaud->Append(_("57600"));
	m_chBaud->Append(_("115200"));

	m_chBaud->SetSelection(1);
}

void wxsertermFrame::closingPort(void){
    if(serComm->IsOpened()){
        serTimer->Stop();
        serComm->Close();
        m_btnPortOpen->SetLabel("Open Port");
        m_btnPortList->Enable(true);
        m_chPort->Enable(true);
        m_chBaud->Enable(true);
    }
}

void wxsertermFrame::onCharReceive(char ch){
    if(ignoreLF){if(ch=='\r')return;}

    m_txtConsole->AppendText(wxString::Format(wxT("%c"),ch));
}

void wxsertermFrame::onTimerTick(wxTimerEvent& event){
    char chr;
    bool isReceive;

    do{
        chr = serComm->ReadChar(isReceive);
        if(isReceive) onCharReceive(chr);
    }while(isReceive);
}

void wxsertermFrame::onPortChoice(wxCommandEvent& event){
    devPort = m_chPort->GetString(m_chPort->GetSelection());
    statusBar->SetStatusText("Closed: "+ devPort +"-"+wxString::Format(wxT("%lu"),devBaud)+"-8N1N",0);
}

void wxsertermFrame::onBaudChoice(wxCommandEvent& event){
    devBaud = wxAtol(m_chBaud->GetString(m_chBaud->GetSelection()));
    statusBar->SetStatusText("Closed: "+ devPort +"-"+wxString::Format(wxT("%lu"),devBaud)+"-8N1N",0);
}

char* wxsertermFrame::wxstr2char(wxString& Text){
    std::string strBuff = Text.ToStdString();

    int size = strBuff.size();
    char *a = new char[size+1];
    a[strBuff.size()] = 0;
    memcpy(a, Text.c_str(), size);

    return a;
}

void wxsertermFrame::onTxtSendEnter(wxCommandEvent& event){
    if(serComm->IsOpened()){
        serReq = m_txtSend->GetValue();
        serReq += "\r\n";

        serComm->Write(wxstr2char(serReq));
        m_txtSend->Clear();
        statusBar->SetStatusText(serReq +" sent",1);
    }
    else{
        statusBar->SetStatusText("Port "+ devPort +" is not opened",1);
    }
}

void wxsertermFrame::defaultPort(void){
    serComm->SetDataSize(8);
    serComm->SetParity('N');
    serComm->SetStopBits(1);
    serComm->SetDTR(false);
    serComm->SetRTS(false);
}

void wxsertermFrame::onBtnPortOpen(wxCommandEvent& event){
    if(m_btnPortOpen->GetLabel()=="Open Port"){
        if(!serComm->IsOpened()){
            serComm->SetComPort(devPort.ToStdString());
            serComm->SetBaudRate(devBaud);
            defaultPort();

            if(serComm->Open()==0){
                m_btnPortOpen->SetLabel("Close Port");
                statusBar->SetStatusText("Opened: "+ devPort +"-"+wxString::Format(wxT("%lu"),devBaud)+"-8N1N",0);
                m_btnPortList->Enable(false);
                m_chPort->Enable(false);
                m_chBaud->Enable(false);
                serTimer->Start(10);
            }
            else{
                serTimer->Stop();
                m_btnPortOpen->SetLabel("Open Port");
                statusBar->SetStatusText("Failed: "+ devPort +"-"+wxString::Format(wxT("%lu"),devBaud)+"-8N1N",0);
                m_btnPortList->Enable(true);
                m_chPort->Enable(true);
                m_chBaud->Enable(true);
            }
        }
    }
    else{
        closingPort();
    }
}

void wxsertermFrame::OnAbout(wxCommandEvent &event)
{
    wxAboutDialogInfo info;

    wxString license =
    L"The MIT License\n"
    L"\n"
    L"Copyright (c) 2021 by Achmadi \n"
    L"\n"
    L"Permission is hereby granted, free of charge, to any person obtaining\n"
    L"a copy of this software and associated documentation files (the\n"
    L"\"Software\"), to deal in the Software without restriction, including\n"
    L"without limitation the rights to use, copy, modify, merge, publish,\n"
    L"distribute, sublicense, and/or sell copies of the Software, and to\n"
    L"permit persons to whom the Software is furnished to do so, subject to\n"
    L"the following conditions:\n"
    L"\n"
    L"The above copyright notice and this permission notice shall be\n"
    L"included in all copies or substantial portions of the Software.\n"
    L"\n"
    L"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND,\n"
    L"EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF\n"
    L"MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND\n"
    L"NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE\n"
    L"LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION\n"
    L"OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION\n"
    L"WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n"
    L"\n";

    wxString desc = "Libraries: \n";
    desc = desc + "wxWidget (v"
			+ wxString::Format(wxT("%i"),wxMAJOR_VERSION) + "."
			+ wxString::Format(wxT("%i"),wxMINOR_VERSION) + "."
			+ wxString::Format(wxT("%i"),wxRELEASE_NUMBER) + ")\n";

    desc = desc + "ceSerial (git)";

    info.SetName("wxWidget Serial Terminal");
    info.SetCopyright("Achmadi@2021");
    info.SetLicence(license);
    info.SetDescription(desc);

    wxAboutBox(info);
}
