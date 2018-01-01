#pragma once

#include <iostream>
#include <string>

using namespace std;

class OnlineWalletsOperations
{
public:
	OnlineWalletsOperations();


	bool get_expected_symbol(string addres_compare) {

		for (int i = 0; i < addres_compare.length(); ++i) {
			if (addres_compare[i] == ' ') return false;
			else if (addres_compare[i] == '+') return false;
			else if (addres_compare[i] == '-') return false;
			else if (addres_compare[i] == '*') return false;
			else if (addres_compare[i] == '/') return false;
			else if (addres_compare[i] == '?') return false;
			else if (addres_compare[i] == '%') return false;
			else if (addres_compare[i] == '$') return false;
			else if (addres_compare[i] == '@') return false;
			else if (addres_compare[i] == '.') return false;
		}

		return true;
	}



	bool execute_validation_ethereum(string addres_compare) {

		if (addres_compare.length() != 42) return false;
		else {
			if (addres_compare[0] != '0' || addres_compare[1] != 'x')return false;
			else if (get_expected_symbol(addres_compare) != true)return false;
		}

		return true;
	}


	bool execute_validation_bitcoin_and_bitcoincash(string addres_compare) {

		if (addres_compare.length() != 34) return false;
		else {
			if (get_expected_symbol(addres_compare) != true)return false;

		}

		return true;
	}



	bool execute_validation_litecoin(string addres_compare) {

		if (addres_compare.length() != 34) return false;
		else {
			if (addres_compare[0] != 'L')return false;
			else if (get_expected_symbol(addres_compare) != true)return false;

		}

		return true;
	}



	~OnlineWalletsOperations();
};

