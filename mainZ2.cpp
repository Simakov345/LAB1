#include <iostream>
#include <cctype>
#include "Z2.h"
#include <locale>
using namespace std;
bool isValid(const string& s)
{
	for(auto c:s)
		if (!iswalpha(c) || !iswupper(c))
			return false;
	return true;
}

int main()
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	bool isTrue = true;
	wcout << L"Добро пожаловать в программу для шифрования." << endl;
	int key;
	wstring text;
	wstring action;
	wcout<<L"Введите ключ: ";
	wcin>>key;
	if (!wcin.good()) {
		wcerr<< L"Ключ неверный!\n";
		return 1;
	}

	Z2 cipher(key);
	do {
		wcin>>action;
		wcout<<L"Укажите действие (exit, encrypt, decrypt): ";
		if (action != L"encrypt" && action != L"decrypt" && action != L"exit") {
			wcout << L"Введите любую последовательность символов, чтобы продолжить.\n";
			wcin >> action;
		}

		if (action == L"encrypt") {
			wcout << L"Введите строку:"<<endl;
			wcin>> text;
			wcout << L"Зашифрованная строка:"<<cipher.encrypt(text)<<endl;
		}
		if (action == L"decrypt") {
			wcout << L"Введите строку:"<<endl; 
			wcin>> text;
			wcout << L"Расшифрованная строка:"<<cipher.decrypt(text)<<endl;
		}
		if (action == L"exit") {
			wcout << L"Программа завершила работу." << endl;
			isTrue = false;
			break;
		}


	} while (isTrue != false);
	return 0;
}
