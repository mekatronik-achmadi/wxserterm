/***************************************************************
 * Name:      wxsertermApp.h
 * Purpose:   Defines Application Class
 * Author:    Achmadi (mekatronik.achmadi@gmail.com)
 * Created:   2021-02-13
 * Copyright: Achmadi ()
 * License:
 **************************************************************/

#ifndef WXSERTERMAPP_H
#define WXSERTERMAPP_H

#include <wx/app.h>

class wxsertermApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WXSERTERMAPP_H
