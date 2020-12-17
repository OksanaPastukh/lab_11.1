#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;
void CreateBIN(char* fname, const int N) // ��������� ����� ������� � �������� �����
{
	ofstream fout(fname, ios::binary); // ������� ���� ��� ������
	int value = 0;
	for (int i = 1;i <= N; i++)
	{
		cout << "������ ����� " << i << " = "; cin >> value;
		fout.write((char*)&value, sizeof(int));

	}
	fout.close();
}

void value(char* fname, char* gname)
{
	ifstream f(fname); // ������� ������ ���� ��� ����������
	ofstream g(gname, ios::binary); // ������� ���� ��� ������
	int value = 0;
	int max = INT_MIN;
	int min = INT_MAX;
	double middle_average_min_max;
	double middle_average;
	int sum = 0;
	int n = 0;
	while (f.read((char*)&value, sizeof(int))) // ���� ����� ���������
	{
		if (value > max) // ���� ���������� ������ ������
		{
			max = value; // - ������� ���� ���������
		} 
		if (value < min) // ���� ���������� ������ ������
		{
			min = value; // - ������� ���� ���������
		} 
		sum = sum + value;
		n++;
	}
	 middle_average = sum / n;
	 middle_average_min_max = (min + max) / 2;
	 g.write((char*)&middle_average, sizeof(double));
	 g.write((char*)&middle_average_min_max, sizeof(double));
	 g.close();
	 f.close();
}
void PrintBIN(char* gname) // ��������� ����� �� �����
{
	ifstream fin(gname, ios::binary); // ������� ���� ��� ����������
	double c; // ���������� ������
	while (fin.read((char*)&c, sizeof(c))) // ���� ����� ��������� ������
	{
		cout << c << endl; // �������� ���� �� �����
	}
	cout << endl;
}
int main()
{
	// binary files
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������
	char fname[100]; // ��'� ������� �����
	char gname[100];
	cout << "enter file name 1: "; cin >> fname;
	int N;
	cout << "������ �������  N: "; cin >> N;
	CreateBIN(fname, N); // ����� ����� ����� � ���������
	cout << "enter file name 2: "; cin >> gname;
	value(fname, gname);
	PrintBIN(gname);
	return 0;
}
