#pragma once
#include "Date.h"
#include "MyTime.h"
#include "MyString.h"

struct Sales
{
	MyTime timeofsale;
	Date dateofsale;
	float sumOfSales = 0;

	void saveSale(FILE* fp)
	{
		fwrite(&timeofsale, sizeof(MyTime), 1, fp);
		fwrite(&dateofsale, sizeof(Date), 1, fp);
		fwrite(&sumOfSales, sizeof(float), 1, fp);
	}
	void loadSale(FILE* fp)
	{
		fread(&timeofsale, sizeof(MyTime), 1, fp);
		fread(&dateofsale, sizeof(Date), 1, fp);
		fread(&sumOfSales, sizeof(float), 1, fp);
	}

};
