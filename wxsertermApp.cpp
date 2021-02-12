/***************************************************************
 * Name:      wxsertermApp.cpp
 * Purpose:   Code for Application Class
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

#include "wxsertermApp.h"
#include "wxsertermMain.h"

IMPLEMENT_APP(wxsertermApp);

bool wxsertermApp::OnInit()
{
    wxsertermFrame* frame = new wxsertermFrame(0L);
    
    frame->Show();
    
    return true;
}
