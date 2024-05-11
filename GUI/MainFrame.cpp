#include "MainFrame.h"
#include <wx/wx.h>
#include <string>

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this);

	wxButton* button1 = new wxButton(panel, wxID_ANY, "", wxPoint(100, 100), wxSize(100,100));
	locations[0] = button1;
	wxButton* button2 = new wxButton(panel, wxID_ANY, "", wxPoint(200, 100), wxSize(100, 100));
	locations[1] = button2;
	wxButton* button3 = new wxButton(panel, wxID_ANY, "", wxPoint(300, 100), wxSize(100, 100));
	locations[2] = button3;
	wxButton* button4 = new wxButton(panel, wxID_ANY, "", wxPoint(100, 200), wxSize(100, 100));
	locations[3] = button4;
	wxButton* button5 = new wxButton(panel, wxID_ANY, "", wxPoint(200, 200), wxSize(100, 100));
	locations[4] = button5;
	wxButton* button6 = new wxButton(panel, wxID_ANY, "", wxPoint(300, 200), wxSize(100, 100));
	locations[5] = button6;
	wxButton* button7 = new wxButton(panel, wxID_ANY, "", wxPoint(100, 300), wxSize(100, 100));
	locations[6] = button7;
	wxButton* button8 = new wxButton(panel, wxID_ANY, "", wxPoint(200, 300), wxSize(100, 100));
	locations[7] = button8;
	wxButton* button9 = new wxButton(panel, wxID_ANY, "", wxPoint(300, 300), wxSize(100, 100));
	locations[8] = button9;

	std::string display_text = "Player 1, click a box to choose your space";
	wxStaticText* infobar = new wxStaticText(panel, wxID_ANY, display_text, wxPoint(450, 100),wxDefaultSize);
	thisstatus = infobar;

	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);
	button3->Bind(wxEVT_BUTTON, &MainFrame::OnButton3Clicked, this);
	button4->Bind(wxEVT_BUTTON, &MainFrame::OnButton4Clicked, this);
	button5->Bind(wxEVT_BUTTON, &MainFrame::OnButton5Clicked, this);
	button6->Bind(wxEVT_BUTTON, &MainFrame::OnButton6Clicked, this);
	button7->Bind(wxEVT_BUTTON, &MainFrame::OnButton7Clicked, this);
	button8->Bind(wxEVT_BUTTON, &MainFrame::OnButton8Clicked, this);
	button9->Bind(wxEVT_BUTTON, &MainFrame::OnButton9Clicked, this);
	CreateStatusBar();

	Game* thisgame = new Game();
	game = thisgame;
	thisstatus->SetLabel("Great Job Players, it was a cat's game!\n Please close out of the program when ready.");
}


void MainFrame::TicTac(int space) {
	if (game->valid_input(space))
	{

		//player makes the move
		locations[space]->SetLabel(game->getmark());
		game->make_move(space);

		//checks game's status
		char checkedchar = game->check_game();
		if (checkedchar  != ' ')
		{
			if (checkedchar != 'C')
			{
				thisstatus->SetLabel("Great Job Player " + to_string(game->getplayer()) + "!!\n Please close out of the program when ready.");
				return;
			}
			else {
				thisstatus->SetLabel("Great Job Players, it was a cat's game!\n Please close out of the program when ready.");
				return;
			}
		}
		//switches to next player
		game->switch_player();
		thisstatus->SetLabel("Player " + to_string(game->getplayer()) + ", Please choose a space");
	}
	else {
		thisstatus->SetLabel("This space was already taken, please try again.");
	}
}

void MainFrame::OnButton1Clicked(wxCommandEvent& evt) {
	wxLogStatus("Top Left Button Clicked");
	TicTac(0);	
}

void MainFrame::OnButton2Clicked(wxCommandEvent& evt) {
	wxLogStatus("Top Middle Button Clicked");
	TicTac(1);
}

void MainFrame::OnButton3Clicked(wxCommandEvent& evt) {
	wxLogStatus("Top Right Button Clicked");
	TicTac(2);
}

void MainFrame::OnButton4Clicked(wxCommandEvent& evt) {
	wxLogStatus("Middle Left Button Clicked");
	TicTac(3);
}

void MainFrame::OnButton5Clicked(wxCommandEvent& evt) {
	wxLogStatus("Middle Button Clicked");
	TicTac(4);
}

void MainFrame::OnButton6Clicked(wxCommandEvent& evt) {
	wxLogStatus("Middle Right Button Clicked");
	TicTac(5);
}

void MainFrame::OnButton7Clicked(wxCommandEvent& evt) {
	wxLogStatus("Bottom Left Button Clicked");
	TicTac(6);
}

void MainFrame::OnButton8Clicked(wxCommandEvent& evt) {
	wxLogStatus("Bottom Middle Button Clicked");
	TicTac(7);
}

void MainFrame::OnButton9Clicked(wxCommandEvent& evt) {
	wxLogStatus("Bottom Right Button Clicked");
	TicTac(8);
}
