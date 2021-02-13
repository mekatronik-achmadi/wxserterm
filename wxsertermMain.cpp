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
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
    statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif
}

wxsertermFrame::~wxsertermFrame()
{
}

void wxsertermFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void wxsertermFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
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
    info.SetCopyright("MIT by Achmadi@2021");
    info.SetLicence(license);
    info.SetDescription(desc);

    wxAboutBox(info);
}
