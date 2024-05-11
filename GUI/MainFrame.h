#pragma once
#include <wx/wx.h>
#include <array>
#include "Game.hpp"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	

private:
	Game* game;
	std::array<wxButton*, 9> locations;
	wxStaticText* thisstatus;

	void TicTac(int space);

	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);
	void OnButton3Clicked(wxCommandEvent& evt);
	void OnButton4Clicked(wxCommandEvent& evt);
	void OnButton5Clicked(wxCommandEvent& evt);
	void OnButton6Clicked(wxCommandEvent& evt);
	void OnButton7Clicked(wxCommandEvent& evt);
	void OnButton8Clicked(wxCommandEvent& evt);
	void OnButton9Clicked(wxCommandEvent& evt);

};

