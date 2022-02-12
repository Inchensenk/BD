#pragma once
#include <iostream>//поток ввода-вывода
#include <string>//строка
#include <fstream>//работа с потоками чтение записи с файла и в файл
#include <Windows.h>//дополнительные функции

using namespace std;//пространство имен стандартного потока ввода-вывода

/*
	Данные:
	1. ФИО 
	2. Дата
	3. Адрес
*/

//ФИО
struct Initials
{
	string surname,//Фамилия 
		name,//Имя
		patronymic;//Отчество
};

//Дата
struct Date
{
	int day,//День 
		month,//Месяц
		year;//Год
};

//Адрес
struct Address
{
	string city;
	int home;
};

//Прототип класса
class Data
{
	//Закрытая часть класса (поля класса)
private:
	Initials initials;
	Date date;
	Address address;

	//открытая часть класса
public:
	//обязательные методы класса
	Data(); //конструктор по умолчанию. Создает пустой объект
	Data(Initials initials_, Date date_, Address address_);//конструктор с параметрами. Создает пустой объект с параметрами
	~Data();//дуструктор. Удалаяет объект

	//не обязательные объекты класса (нужны для выволнения данной задачи)
	//вывод данных в консоль
	void Print();
	//ввод данных
	void DataEntry(Initials initials_, Date date_, Address address_);
	//вывод данных (полей) из класса
	Initials GetInitials() { return initials; };
	Date GetDate() { return date; };
	Address GetAddress() { return address; };

	//перегрузка оператора =
	Data& operator = (Data d_o);
};