#pragma once
#include <iostream>
#include <windows.h>
#include <string>


using namespace std;



class ClipBoardOperations
{
public:
	ClipBoardOperations();


	string get_data_inside_buffer() {

		if (!OpenClipboard(nullptr)) {
			cout << "Failed open ClipBoard \n";
		}

		HANDLE hData = GetClipboardData(CF_TEXT);
		if (hData == nullptr) {}


		char * pszText = static_cast<char*>(GlobalLock(hData));
		if (pszText == nullptr) {}

		string text(pszText);

		GlobalUnlock(hData);

		CloseClipboard();

		return text;
	}


	void erase_data_inside_clipboard() {

		if (!OpenClipboard(nullptr)){
			cout << "Failed open ClipBoard \n";
		}

		if (!EmptyClipboard()){
			cout << "Verified ClipBoard is empty \n";
		}
		
		HGLOBAL hGlob = GlobalAlloc(GMEM_FIXED, 64);
		strcpy_s((char*)hGlob, 64, "");
	
		if (::SetClipboardData(CF_TEXT, hGlob) == NULL)
		{
			CloseClipboard();
			GlobalFree(hGlob);
			return;
		}
		CloseClipboard();
	}





	~ClipBoardOperations();
};

