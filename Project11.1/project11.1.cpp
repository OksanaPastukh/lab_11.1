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

void value(char* fname, char* gname)
{
	ifstream f(fname); // відкрили перший файл для зчитування
	ofstream g(gname, ios::binary); // відкрили файл для запису
	int value = 0;
	int max = INT_MIN;
	int min = INT_MAX;
	double middle_average_min_max;
	double middle_average;
	double sum = 0;
	double n = 0;
	while (f.read((char*)&value, sizeof(int))) // поки можна зчитувати
	{
		if (value > max) // якщо прочитаний символ менший
		{
			max = value; // - вважаємо його мінімальним
		} 
		if (value < min) // якщо прочитаний символ менший
		{
			min = value; // - вважаємо його мінімальним
		} 
		sum = sum + value;
		n++;
	}
	 middle_average = sum / n;
	 middle_average_min_max = ((double)min +(double)max) / 2;
	 g.write((char*)&middle_average, sizeof(double));
	 g.write((char*)&middle_average_min_max, sizeof(double));
	 g.close();
	 f.close();
}
void PrintBIN(char* gname) // виведення файлу на екран
{
	ifstream fin(gname, ios::binary); // відкрили файл для зчитування
	double middle_average; // прочитаний символ
	fin.read((char*)&middle_average, sizeof(middle_average));
	double middle_average_min_max;
	fin.read((char*)&middle_average_min_max, sizeof(middle_average_min_max));
    cout << "Середнье значення всіх компонентів  " << middle_average << endl  // виводимо його на екран
		 << "Середнье значення мінімального і максимального значення  " << middle_average_min_max << endl;
}
int main()
{
	// binary files
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	char fname[100]; // ім'я першого файлу
	char gname[100];
	cout << "Ім'я файлу з послідовністью чисел : "; cin >> fname;
	int N;
	cout << "Введіть кількість  N: "; cin >> N;
	CreateBIN(fname, N); // ввели рядки файлу з клавіатури
	cout << "Ім'я файлу для збереження результату роботи : "; cin >> gname;
	value(fname, gname);
	PrintBIN(gname);
	return 0;
}
