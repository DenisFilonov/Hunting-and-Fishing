#pragma once
#include"Date.h"
#include"MyString.h"

struct Commodity
{
	MyString name; //Наименование товара
	int departureOf = 0; //отдел товара: охотничий(оружия), рыбацкий(удочки, снасти), экипировка (одежда, обвесы, патроны), технический(лодка, прицеп, авто)
	MyString category; //категория товара: расходник, оружие, инструмент, одежда, 
	MyString type; //тип товара, входящий в категорию: Одежда: головные уборы, комбинензоны, носки, обувь, перчатки
	/*ОРУЖИЕ, ПАТРОНЫ, НОЖИ И ИНСТРУМЕНТЫ, ТЮНИНГ, ОДЕЖДА И ОБУВЬ, АКСЕССУАРЫ, ФОНАРИ, СНАРЯЖЕНИЕ, ЧИСТКА И УХОД, АКТИВНЫЙ ОТДЫХ, 
		СЕЙФЫ ОРУЖЕЙНЫЕ, ЦЕЛЕУКАЗАТЕЛИ ЛАЗЕРНЫЕ, ОПТИКА, НАБОРЫ ДЛЯ ТО, СУВЕНИРЫ, ТОВАРЫ С ПОДАРКАМИ, УЦЕНЕННЫЕ ТОВАРЫ*/
	/*Удилища, катушки, оснастка (крючки, кормушки, поплавки), приманки, прикормки, одежда, 
	(лодки, палатки, зонты/тенты, мангалы)*/
	MyString description; //небольшое описание товара
	MyString characteristic; //ТТХ
	MyString package; //Упаковка
	Date arrived; //дата поступления
	int amount = 0; //количество в наличии
	float price = 0; //цена товара

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
void printThisSection(Commodity* arr, int size, int departureOf);//отдел товара:
void printThisCategory(Commodity* arr, int size, const char* category);//категория товара:
float totalPriseInThisSection(Commodity* arr, int size, int departureOf);//сумма всего товара в данном отделе, это для бухгалтерии

bool upPrice(Commodity a, Commodity b);
bool downPrice(Commodity a, Commodity b);
bool upDate(Commodity a, Commodity b);
bool downDate(Commodity a, Commodity b);
void sortCommodity(Commodity* arr, int size, bool(*cmp)(Commodity, Commodity));



void saveStore(Commodity* arr, int size);
void loadStore(Commodity*& arr, int& size);