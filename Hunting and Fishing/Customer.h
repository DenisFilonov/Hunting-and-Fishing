#pragma once
#include"Staff.h"

struct Client
{
	MyString nameOfClient;
	long long idNumber = 0;
	Date dateOfBirth;
	MyString telNumber;
	MyString email;
	MyString addressOfClient;
	
	int amountofbuying = 0;
	Sales* arrs = nullptr;
	float sumOfBuy = 0; //после удаления покупки надо вычесть отсюда сумму удалённой покупки

	void fillCustomer();
	void showCustomer();
	void delCustomerData();
	void addBuy(float sum);
	void delBuy(int id);
	float calcTotalBuys();

	void saveCustomer(FILE* fp);
	void loadCustomer(FILE* fp);
};

void addCustomer(Client*& arr, int& size);
void delCustomerByID(Client*& arr, int& size, int id);
void editCustomersData(Client* arr, int size, int id);
void findCustomerByName(Client* arr, int size, const char* name);
int findCustomerByPhoneNumber(Client* arr, int size, const char* phone);
void showAllCustomers(Client* arr, int size);

void sortCustomersByTotalBuying(Client* arr, int size);

float calcCustomersPurchases(Client* arr, int size, const char* number);
float calcAllCustomersPurchases(Client* arr, int size);


void saveClients(Client* arr, int size);
void loadClients(Client*& arr, int& size);


//void delCustomer(Client*& arr, int& size, const char* name);