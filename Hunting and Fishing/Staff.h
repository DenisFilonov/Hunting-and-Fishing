#pragma once
#include"Date.h"
#include"MyString.h"
#include"Sales.h"
#include"Commodity.h"


struct Worker
{
	MyString nameOfWorker;//���
	MyString department;//�����
	MyString position; // ���������
	int rank = 0;//���� ���������: �����, ������� ���������, �����������, �����������
	Date dateofbirth;//��
	MyString contact; // �������
	MyString addressOfWorker; // ����� ����������
	Date startwork; // ������ ������
	int salary = 0; // �����

	int amountOfSales = 0;
	Sales* arr = nullptr;

	void fillWorker();
	void showWorker();
	void delWorkerData();

	void addSale(float sum);
	void delSale(int id);

	void saveWorker(FILE* fp);
	void loadWorker(FILE* fp);
};

void addWorker(Worker*& arr, int& size);
void delWorkerByID(Worker*& arr, int& size, int id);
void editWorkersData(Worker* arr, int size, int id);
void showDepartment(Worker* arr, int size, const char* dep);
int findIDByInitials(Worker* arr, int size, const char* name);
void showAllWorkers(Worker* arr, int size);


void sortWorkers(Worker* arr, int size, bool(*cmp)(Worker, Worker));
bool upAge(Worker a, Worker b);
bool downAge(Worker a, Worker b);
bool upRank(Worker a, Worker b);
bool downRank(Worker a, Worker b);
bool upStartWork(Worker a, Worker b);
bool downStartWork(Worker a, Worker b);
bool upDepartment(Worker a, Worker b);
bool downDepartment(Worker a, Worker b);



void saveWorkers(Worker* arr, int size);
void loadWorkers(Worker*& arr, int& size);


/* ������

void addWorker(Worker*& arr, int& size);
void delWorker(Worker*& arr, int& size, const char* name);
void delWorkerByID(Worker*& arr, int& size, int id);
void findWorkerByName(Worker* arr, int size, const char* name);
void editWorkersData(Worker* arr, int size, int id);
void showDepartment(Worker* arr, int size, const char* dep);
int findIDByInitials(Worker* arr, int size, const char* name);
void showAllWorkers(Worker* arr, int size);


bool upAge(Worker a, Worker b);
bool downAge(Worker a, Worker b);
bool upRank(Worker a, Worker b);
bool downRank(Worker a, Worker b);
bool upStartWork(Worker a, Worker b);
bool downStartWork(Worker a, Worker b);
bool upDepartment(Worker a, Worker b);
bool downDepartment(Worker a, Worker b);*/
