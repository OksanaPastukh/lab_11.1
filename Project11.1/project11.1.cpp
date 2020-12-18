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
	double sum = 0;
	double n = 0;
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
	 middle_average_min_max = ((double)min +(double)max) / 2;
	 g.write((char*)&middle_average, sizeof(double));
	 g.write((char*)&middle_average_min_max, sizeof(double));
	 g.close();
	 f.close();
}
void PrintBIN(char* gname) // ��������� ����� �� �����
{
	ifstream fin(gname, ios::binary); // ������� ���� ��� ����������
	double middle_average; // ���������� ������
	fin.read((char*)&middle_average, sizeof(middle_average));
	double middle_average_min_max;
	fin.read((char*)&middle_average_min_max, sizeof(middle_average_min_max));
    cout << "�������� �������� ��� ����������  " << middle_average << endl  // �������� ���� �� �����
		 << "�������� �������� ���������� � ������������� ��������  " << middle_average_min_max << endl;
}
int main()
{
	// binary files
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������
	char fname[100]; // ��'� ������� �����
	char gname[100];
	cout << "��'� ����� � ������������ ����� : "; cin >> fname;
	int N;
	cout << "������ �������  N: "; cin >> N;
	CreateBIN(fname, N); // ����� ����� ����� � ���������
	cout << "��'� ����� ��� ���������� ���������� ������ : "; cin >> gname;
	value(fname, gname);
	PrintBIN(gname);
	return 0;
}
