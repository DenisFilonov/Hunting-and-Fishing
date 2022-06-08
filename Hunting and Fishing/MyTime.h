#pragma once
#include <iostream> 
#include <ctime> 
#include <cstdlib> 
#include <cmath>
#include <cstring>
using namespace std;


struct MyTime
{
	//------------------Переменные(Свойства,поля)-----------------
	int hours = 0;
	int min = 0;
	int sec = 0;
	//------------------Функции(Методы) - внутри структуры/класса-

	void filltime()
	{
		cout << "HH MM SS: ";
		cin >> hours >> min >> sec;
	}
	void printTime()
	{
		cout << hours / 10 << hours % 10 << ":" << min / 10 << min % 10 << ":" << sec / 10 << sec % 10 << endl;
	}
	void getNowTime()
	{
		time_t now = time(0); // тек. млсек
		tm* obj = new tm; // создание пустого obj
		localtime_s(obj, &now); // заполнение obj данными, стандартная функция

		hours = obj->tm_hour;
		min = obj->tm_min;
		sec = obj->tm_sec;
		delete obj;
	}
	char* toString()
	{
		// 00:00:00 = 9 байт с \0
		char* str = new char[9];
		//%d(int), %f(float), %lf(double)
		sprintf_s(str, 9, "%d%d:%d%d:%d%d", hours / 10, hours % 10, min / 10, min % 10, sec / 10, sec % 10);

		return str;
	}


	void addSecond()
	{
		sec++;
		if (sec == 60)
		{
			sec = 0;
			min++;
			if (min == 60) 
			{
				min = 0;
				hours++;
			}
			if (hours == 24) hours = 0;
		}
	}		
	void delSecond()
	{
		sec--;
		if (sec == -1)
		{
			sec = 59;
			min--;
			if (min == -1)
			{
				min = 59;
				hours--;
				if (hours == -1) hours = 23;
			}
		}
	}
	void addMinute()
	{
		min++;
		if (min == 60)
		{
			min = 0;
			hours++;
			if (hours == 24) hours = 0;
		}
	}
	void delMinute()
	{
		min--;
		if (min == -1)
		{
			min = 59;
			hours--;
			if (hours == -1) hours = 23;
		}
	}
	void addHour() 
	{
		hours++;
		if (hours == 24) hours = 0;
	}
	void delHour()
	{
		hours--;
		if (hours == -1) hours = 23;
	}

	/*int all = (hours * 3600 + min * 60 + sec) - s;
	 hours = all/3600;
	 min = (all%3600)/60
	sec = all%60;*/

	void addSeconds(int s)
	{
		for (int i = 0; i < s; i++)
		{
			addSecond();
		}
	};
	void delSeconds(int s)
	{
		for (int i = 0; i < s; i++)	
			delSecond();	
	};
	void addMinutes(int m)
	{
		for (int i = 0; i < m; i++)
		addMinute();
	};
	void delMinutes(int m)
	{
		for (int i = 0; i < m; i++)
		delMinute();
	};
	void addHours(int h)
	{
		for (int i = 0; i < h; i++)
		addHour();
	};
	void delHours(int h)
	{
		for (int i = 0; i < h; i++)
		delHour();
	};
};

