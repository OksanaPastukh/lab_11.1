#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
void CreateBIN(char* fname, const int N) // створення файлу символів з введених рядків
{
	ofstream fout(fname, ios::binary); // відкрили файл для запису
	int value = 0;
	for (int i = 1;i <= N; i++)
	{
		cout << "Введіть число " << i << " = "; cin >> value;
		fout.write((char*)&value, sizeof(int));

	}
	fout.close();
}

int max_value(char* fname)
{
	ifstream fout(fname); // відкрили перший файл для зчитування
	int value = 0;
	int max = 0;
	while (fout.read((char*)&value, sizeof(int))) // поки можна зчитувати
	{
		if (value > max) // якщо прочитаний символ менший
		{
			max = value; // - вважаємо його мінімальним
		} // символів
	}
	return max;
}

int main()
{
	// binary files
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	char fname[100]; // ім'я першого файлу
	cout << "enter file name 1: "; cin >> fname;
	int N;
	cout << "Введіть кількість  N: "; cin >> N;
	CreateBIN(fname, N); // ввели рядки файлу з клавіатури
	cout << "Maximal :" << max_value(fname) << endl;
	return 0;
}