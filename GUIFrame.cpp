///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.9.0 Feb  8 2021)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	mbar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* menuFileQuit;
	menuFileQuit = new wxMenuItem( fileMenu, idMenuQuit, wxString( wxT("&Quit") ) + wxT('\t') + wxT("Alt+F4"), wxT("Quit the application"), wxITEM_NORMAL );
	fileMenu->Append( menuFileQuit );

	mbar->Append( fileMenu, wxT("&File") );

	helpMenu = new wxMenu();
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, idMenuAbout, wxString( wxT("&About") ) + wxT('\t') + wxT("F1"), wxT("Show info about this application"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpAbout );

	mbar->Append( helpMenu, wxT("&Help") );

	this->SetMenuBar( mbar );

	statusBar = this->CreateStatusBar( 2, wxSTB_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bMain;
	bMain = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bControl;
	bControl = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSettings;
	bSettings = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bPort;
	bPort = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bPortSet;
	bPortSet = new wxBoxSizer( wxHORIZONTAL );

	m_lblPort = new wxStaticText( this, wxID_ANY, wxT("Port"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_lblPort->Wrap( -1 );
	bPortSet->Add( m_lblPort, 1, wxALL, 5 );

	wxArrayString m_chPortChoices;
	m_chPort = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_chPortChoices, 0 );
	m_chPort->SetSelection( 0 );
	bPortSet->Add( m_chPort, 1, wxALL, 5 );


	bPort->Add( bPortSet, 0, wxEXPAND, 5 );

	wxBoxSizer* bBaud;
	bBaud = new wxBoxSizer( wxHORIZONTAL );

	m_lblBaud = new wxStaticText( this, wxID_ANY, wxT("Baudrate"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_lblBaud->Wrap( -1 );
	bBaud->Add( m_lblBaud, 1, wxALL, 5 );

	wxArrayString m_chBaudChoices;
	m_chBaud = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_chBaudChoices, 0 );
	m_chBaud->SetSelection( 0 );
	bBaud->Add( m_chBaud, 1, wxALL, 5 );


	bPort->Add( bBaud, 0, wxEXPAND, 5 );


	bSettings->Add( bPort, 1, wxEXPAND, 5 );

	wxBoxSizer* bOther;
	bOther = new wxBoxSizer( wxVERTICAL );

	m_lblDataBit = new wxStaticText( this, wxID_ANY, wxT("DataBit: 8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblDataBit->Wrap( -1 );
	bOther->Add( m_lblDataBit, 0, wxALL, 5 );

	m_StopBit = new wxStaticText( this, wxID_ANY, wxT("StopBit: 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_StopBit->Wrap( -1 );
	bOther->Add( m_StopBit, 0, wxALL, 5 );

	m_lblParFlow = new wxStaticText( this, wxID_ANY, wxT("Parity/Flow: None"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblParFlow->Wrap( -1 );
	bOther->Add( m_lblParFlow, 0, wxALL, 5 );


	bSettings->Add( bOther, 1, wxEXPAND, 5 );

	wxBoxSizer* bButton;
	bButton = new wxBoxSizer( wxVERTICAL );

	m_btnPortList = new wxButton( this, wxID_ANY, wxT("ReList Port"), wxDefaultPosition, wxDefaultSize, 0 );
	bButton->Add( m_btnPortList, 0, wxALL, 5 );

	m_btnPortOpen = new wxButton( this, wxID_ANY, wxT("Open Port"), wxDefaultPosition, wxDefaultSize, 0 );
	bButton->Add( m_btnPortOpen, 0, wxALL, 5 );


	bSettings->Add( bButton, 0, wxEXPAND, 5 );


	bControl->Add( bSettings, 0, wxEXPAND, 5 );


	bMain->Add( bControl, 0, wxEXPAND, 5 );

	wxBoxSizer* bText;
	bText = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bConsole;
	bConsole = new wxBoxSizer( wxHORIZONTAL );

	m_lblConsole = new wxStaticText( this, wxID_ANY, wxT("Received Text"), wxDefaultPosition, wxDefaultSize, 0 );
	m_lblConsole->Wrap( -1 );
	bConsole->Add( m_lblConsole, 1, wxALL|wxEXPAND, 5 );

	m_btnClear = new wxButton( this, wxID_ANY, wxT("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	bConsole->Add( m_btnClear, 0, wxALL, 5 );


	bText->Add( bConsole, 0, wxEXPAND, 5 );

	m_txtConsole = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_READONLY );
	bText->Add( m_txtConsole, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSend;
	bSend = new wxBoxSizer( wxHORIZONTAL );

	m_lblSend = new wxStaticText( this, wxID_ANY, wxT("Send Text"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_lblSend->Wrap( -1 );
	bSend->Add( m_lblSend, 0, wxALL|wxEXPAND, 5 );

	m_txtSend = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSend->Add( m_txtSend, 1, wxALL, 5 );


	bText->Add( bSend, 0, wxEXPAND, 5 );


	bMain->Add( bText, 1, wxEXPAND, 5 );


	this->SetSizer( bMain );
	this->Layout();

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	fileMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ), this, menuFileQuit->GetId());
	helpMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ), this, menuHelpAbout->GetId());
	m_chPort->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::onPortChoice ), NULL, this );
	m_chBaud->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::onBaudChoice ), NULL, this );
	m_btnPortOpen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::onBtnPortOpen ), NULL, this );
	m_btnClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::onBtnClear ), NULL, this );
	m_txtSend->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::onTxtSendEnter ), NULL, this );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	m_chPort->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::onPortChoice ), NULL, this );
	m_chBaud->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( GUIFrame::onBaudChoice ), NULL, this );
	m_btnPortOpen->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::onBtnPortOpen ), NULL, this );
	m_btnClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::onBtnClear ), NULL, this );
	m_txtSend->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUIFrame::onTxtSendEnter ), NULL, this );

}
