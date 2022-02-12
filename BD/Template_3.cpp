// BD.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//https://youtu.be/1FeAag6aIio?list=PLpWjhCHQwH_oLYebZ2BFRHDyDJw5S7VjZ
/*Массив объектов класса*/
/*Одномерный массив, в качестве элементов выступают объекты класса*/
#include "Function.h"
//глобальная переменная, отвечающая за выбранное действие
int _stateMenu;
void menu()
{
	cout << "Выберите действие: " << endl
		<< "(0) Выход из программы" << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод данных" << endl
		<< "(3) Изменение данных" << endl
		<< "(4) Добавление данных" << endl
		<< "(5) Удаление данных" << endl
		<< "(6) Сортировка данных" << endl
		<< "(7) Сохранение данных" << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}
int main()
{
	//русификация консоли вводв/ввывода
	SetConsoleCP(1251);//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);//установка кодовой страницы win-cp 1251 в поток вывода 

	menu();//вызов меню
	int _actions;//дополнительное действие при выполнение какого-либо действия
	string fileName;//название файла

	int _size = 0;//колличество данных
	Data* d = new Data[_size];//массив данных

	//пока мы не нажмем 0, программа работает
	while (0 != _stateMenu)
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls");//очистка консоли

			cout << "Dвести данные вручную или считать из файла?: ";
			cin >> _actions;
			if (1 == _actions)
			{
				DataEntry(d, _size);
			}
			else
			{
				//считываем из файла
				/*
				* 
				cout<< "Введите название файла: ";
				cin >> fileName;//Input.txt

				DataReading(d, _size, FileName);
				*/
				DataReading(d, _size, "Input.txt");
			}
			system("pause");//задержка консоли
			system("cls");//очистка консоли
			menu();//вызов меню
			break;
			/////////////////////////////////////////////////////
		case 2:
			system("cls");//очистка консоли
			if (0 != _size)
			{
				Print(d, _size);
			}
			else
			{
				cout << "Данные пусты!" << endl;
			}
			system("pause");//задержка консоли
			system("cls");//очистка консоли
			menu();//вызов меню
			break;
			//////////////////////////////////////////////////////
		case 3:
			system("cls");//очистка консоли
			if (0 != _size)
			{
				DataChange(d, _size);
			}
			else
			{
				cout << "Данные пусты!" << endl;
			}
			system("pause");//задержка консоли
			system("cls");//очистка консоли
			menu();//вызов меню
			break;
			//////////////////////////////////////////////////////
		case 4:
			system("cls");//очистка консоли
			if (0 != _size)
			{
				AddData(d, _size);
			}
			else
			{
				cout << "Данные пусты!" << endl;
			}
			system("pause");//задержка консоли
			system("cls");//очистка консоли
			menu();//вызов меню
			break;
			//////////////////////////////////////////////////////
		case 5:
			system("cls");//очистка консоли

			if (0 != _size)
			{
				DeleteData(d, _size);
			}
			else
			{
				cout << "Данные пусты!" << endl;
			}
			system("pause");//задержка консоли
			system("cls");//очистка консоли
			menu();//вызов меню
			break;
			//////////////////////////////////////////////////////
		case 6:
			system("cls");//очистка консоли

			if (0 != _size)
			{
				SortingData(d, _size);
			}
			else
			{
				cout << "Данные пусты!" << endl;
			}
			system("pause");//задержка консоли
			system("cls");//очистка консоли
			menu();//вызов меню
			break;
			//////////////////////////////////////////////////////
		case 7:
			system("cls");//очистка консоли

			if (0 != _size)
			{
				/*
				cout<< "Введите название файла: ";
				cin >> fileName;//Output.txt

				SaveData(d, _size, fileName);
				*/

				SaveData(d, _size, "Out.txt");
			}
			else
			{
				cout << "Данные пусты!" << endl;
			}
			system("pause");//задержка консоли
			system("cls");//очистка консоли
			menu();//вызов меню
			break;
			//////////////////////////////////////////////////////
		default:
			cout << "Пункт меню введен не верно!" << endl;
			system("cls");//очистка консоли
			menu();//вызов меню
			break;
		}
	}
	system("cls");//очистка консоли
	cout << "Работа завершена!" << endl;
	system("pause");//задержка консоли
}
