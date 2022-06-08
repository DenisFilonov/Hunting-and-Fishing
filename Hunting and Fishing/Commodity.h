#pragma once
#include"Date.h"
#include"MyString.h"

struct Commodity
{
	MyString name; //������������ ������
	int departureOf = 0; //����� ������: ���������(������), ��������(������, ������), ���������� (������, ������, �������), �����������(�����, ������, ����)
	MyString category; //��������� ������: ���������, ������, ����������, ������, 
	MyString type; //��� ������, �������� � ���������: ������: �������� �����, ������������, �����, �����, ��������
	/*������, �������, ���� � �����������, ������, ������ � �����, ����������, ������, ����������, ������ � ����, �������� �����, 
		����� ���������, ������������� ��������, ������, ������ ��� ��, ��������, ������ � ���������, ��������� ������*/
	/*�������, �������, �������� (������, ��������, ��������), ��������, ���������, ������, 
	(�����, �������, �����/�����, �������)*/
	MyString description; //��������� �������� ������
	MyString characteristic; //���
	MyString package; //��������
	Date arrived; //���� �����������
	int amount = 0; //���������� � �������
	float price = 0; //���� ������

	void fillComm();
	void showComm();
	void delCommData();

	void saveComm(FILE* fp);
	void loadComm(FILE* fp);
};

void addCommodity(Commodity*& arr, int& size);
void delCommodity(Commodity*& arr, int& size);
void showStore(Commodity* arr, int size);

void editDataOfCommodity(Commodity* arr, int size);
int getIDbyName(Commodity* arr, int size, const char* name);
void showCommodity(Commodity* arr, int size, const char* name);
void printThisSection(Commodity* arr, int size, int departureOf);//����� ������:
void printThisCategory(Commodity* arr, int size, const char* category);//��������� ������:
float totalPriseInThisSection(Commodity* arr, int size, int departureOf);//����� ����� ������ � ������ ������, ��� ��� �����������

bool upPrice(Commodity a, Commodity b);
bool downPrice(Commodity a, Commodity b);
bool upDate(Commodity a, Commodity b);
bool downDate(Commodity a, Commodity b);
void sortCommodity(Commodity* arr, int size, bool(*cmp)(Commodity, Commodity));



void saveStore(Commodity* arr, int size);
void loadStore(Commodity*& arr, int& size);