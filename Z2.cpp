#include "Z2.h"

using namespace std;

std::wstring Z2::encrypt(const std::wstring& open_text) // шифрование
{
	wstring tabl = open_text;
	int dlina, kolvo, index, x;
	dlina = open_text.length(); // введенный текст
	kolvo = (dlina - 1) / kluch + 1; // количество столбцов
	x = 0;
	for (int i = kluch; i > 0; i--) { // столбцы
		for (int j = 0; j < kolvo; j++) { // строки
			index = i+kluch*j;
			if (index-1 < dlina) {
				tabl[x] = open_text[index-1];
				x++;
			}
		}
	}
	return tabl;
}

std::wstring Z2::decrypt(const std::wstring& cipher_text) // расшифрование
{
	wstring tabl = cipher_text;
	int dlina, kolvo, index, x;
	dlina = cipher_text.length();
	kolvo = (dlina - 1) / kluch + 1; // количество столбцов
	x = 0;
	for (int i = kluch; i > 0; i--) { // столбцы
		for (int j = 0; j < kolvo; j++) { // строки
			index = i+kluch*j;
			if (index-1 < dlina) {
				tabl[index-1] = cipher_text[x];
				x++;
			}
		}
	}
	return tabl;
}
