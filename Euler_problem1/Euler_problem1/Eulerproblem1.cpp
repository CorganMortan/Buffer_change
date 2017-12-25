// Eulerproblem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <thread>
using namespace std;

/*int multiples_3orand5(int count) {
	int sum = 0;
	for (int i = 1; i < count; ++i) {
		if (i % 3 == 0)sum += i;
		else if(i % 5==0)sum += i;
	}

	return sum;
}



int milionfibonaci(int count) {
	unsigned int sum = 0, mem_val = 1, mem_val1 = 1,mem=0;
	for (int i = 0; i < count; ++i) {

		mem = mem_val+mem_val1;
		mem_val1 = mem_val;
		mem_val = mem;

		if (mem < 4000000)if (mem % 2 == 0)sum += mem;
	
		//cout << mem << "\n";
	}

	return sum;
}*/


//string validate_command(string command) {
//	string mem = "",copy_rez="";
//	for (int i = 0; i < command.length(); ++i) {
//	
//		if ( command[i] != ' ') { mem += command[i]; }
//		else {
//			//cout << "mem: " << mem << "\n";
//			cout << "mem: " << mem.length() << "\n";
//	
//			if (mem.compare("Name") != 0)cout << "yes";
//		/*	if (mem.compare("Name") != 0 ) {
//				copy_rez += mem;
//				mem = "";
//				//cout << "rez: " << copy_rez << "\n";
//				//cout << "mem: " << mem << "\n";
//				//break;
//			}*/
//			
//		}
//	}
//
//	return copy_rez;
//}



/*
string validate_command1(string command) {
	string mem = "", copy_rez = "";
	for (int i = 0; i < command.length(); ++i) {
		if (command[i] != '\n') {
			copy_rez += command[i];
	     }
	}

	return copy_rez;
}




string get_command(string command_1) {
	string result_command="";
	const char *com_1 = command_1.c_str();
	char buf[1024];
	FILE *in;
	if ((in = _popen(com_1,"r")) == NULL) {
		cout << "Failed executed command.";
	}

	while (fgets(buf,1024,in)) {
			result_command += buf;
	}

	_pclose(in);

	return result_command;
}*/

// get cpu name: wmic cpu get name
//get gpu name: wmic path win32_VideoController get name
//get ram delail: wmic MemoryChip get BankLabel, Capacity, MemoryType, TypeDetail, Speed
//get system name: wmic os get Caption /value



string get_data_inside_buffer() {

	if (!OpenClipboard(nullptr)) {

	}

	HANDLE hData = GetClipboardData(CF_TEXT);
	if (hData == nullptr) {}


	char * pszText = static_cast<char*>(GlobalLock(hData));
	if (pszText == nullptr) {}
	
	string text(pszText);

	// Release the lock
	GlobalUnlock(hData);


	CloseClipboard();

	return text;
}


void erase_data_inside_clipboard() {

	if (!OpenClipboard(nullptr))
	{
		
	}
	// Remove the current Clipboard contents
	if (!EmptyClipboard())
	{
	
	}
	// Get the currently selected data
	HGLOBAL hGlob = GlobalAlloc(GMEM_FIXED, 64);
	strcpy_s((char*)hGlob, 64, "");
	// For the appropriate data formats...
	if (::SetClipboardData(CF_TEXT, hGlob) == NULL)
	{
		CloseClipboard();
		GlobalFree(hGlob);
		return;
	}
	CloseClipboard();
}

void check_buffer() {
	int i = 0;
	while (true)
	{
	
		cout << "Verified buffer:";
		string data = get_data_inside_buffer();
		if (data == "OnEditCopy()") { cout << "erase clipboard"; erase_data_inside_clipboard(); }
		else {
			cout << data << "\n";
		}

		cout << "------------------------------------------- \n";
		//++i;
		Sleep(1000);
	}
}


int main()
{
	thread first(check_buffer);

	first.join();




	//cout<<multiples_3orand5(1000)<<"\n";
	//cout<<milionfibonaci(100)<<"\n";
	/*string execute_command[] = {"wmic cpu get name",
		"wmic path win32_VideoController get name",
		"wmic computersystem get TotalPhysicalMemory",
		"wmic os get Caption /value",
		"ipconfig | findstr /i ipv4"};
	string colect[100],final_res="";*/
	//string view_1 = get_command("wmic os get Caption /value");

/*	for (int i = 0; i <sizeof(execute_command) / sizeof(execute_command[0]); ++i) {
		colect[i] = get_command(execute_command[i]);
	}

	//std::cout << validate_command1(colect[0])<<"\n";
	for (int i = 0; i < 5; ++i) {
		
		if (i != 4) { colect[i]= validate_command1(colect[i]); }
		else colect[i] = colect[i];
	
	}*/

	//for (int i = 0; i < 5; ++i)final_res += final_res + colect[i];
/*	final_res = colect[0] + " " + colect[1] + " " + colect[2];
	std::cout << final_res <<"\n";
	std::cout << "---------------------------------------------------------------\n";*/
	//std::cout << validate_command(colect);


	/*std::cout << view_1<<"\n";
	std::cout << "---------------------------------------------------------------\n";
	std::cout << view_1<<"\n";
	std::cout << "///////////////////////////////////////////////////////////////\n";*/

	system("pause");
    return 0;
}

