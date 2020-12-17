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

int max_value(char* fname)
{
	ifstream fout(fname); // ������� ������ ���� ��� ����������
	int value = 0;
	int max = 0;
	while (fout.read((char*)&value, sizeof(int))) // ���� ����� ���������
	{
		if (value > max) // ���� ���������� ������ ������
		{
			max = value; // - ������� ���� ���������
		} // �������
	}
	return max;
}

int main()
{
	// binary files
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������
	char fname[100]; // ��'� ������� �����
	cout << "enter file name 1: "; cin >> fname;
	int N;
	cout << "������ �������  N: "; cin >> N;
	CreateBIN(fname, N); // ����� ����� ����� � ���������
	cout << "Maximal :" << max_value(fname) << endl;
	return 0;
}