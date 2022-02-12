#pragma once
#include "Data.h"

//Прототипы функций
//Ввод данных вручную
void DataEntry(Data* (&d), int& n);
//Чтение из файла
void DataReading(Data* (&d), int& n, string fileName);
//Вывод в консоль
void Print(Data* d, int n);
//Изменение данных
void DataChange(Data* d, int n);
//Копия данных массива
void Copy(Data* d_n, Data* d_o, int n);
//Добавление данных
void AddData(Data* (&d), int& n);
//Удаление данных
void DeleteData(Data* (&d), int& n);
//Сортировка 
void SortingData(Data* d, int n);
//Сохранение данных
void SaveData(Data* d, int n, string filename);


