#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>
class Z2
{
private:
	int kluch; // кол-во столбцов
public:
	Z2()=delete; // запрет конструктора без параметров
	Z2(const int& key) :kluch(key) {};
	std::wstring encrypt(const std::wstring& open_text); // зашифрование
	std::wstring decrypt(const std::wstring& cipher_text); // расшифрование
};
