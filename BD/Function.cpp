#include "Function.h"
//передаем первым параметром функции ссылку на массив, чтобы не создавался дубликат массива как при записи Data* d
void DataEntry(Data* (&d), int& n)
{
	//временные переменные
	Initials initials;
	Date date;
	Address address;
	
	cout << "Введите размер массива: ";
	cin >> n;

	//выделение памяти для массива данных
	//если бы параметр функции был бы передан так: Data* d, то выделенная память осталась бы только внутри функции DataEntry
	d = new Data[n];

	//вводим данные
	for (int i = 0; i < n; i++)
	{
		cout << "Введите ФИО: ";
		cin >> initials.surname >> initials.name >> initials.patronymic;

		cout << "Введите Дату: ";
		cin >> date.day >> date.month >> date.year;

		cout << " Введите Адрес: ";
		cin >> address.city >> address.home;

		//Добавление новых данных в элемент массива объекта класса
		//так как каждый элемент массыва это обьект, у объекта есть определенные методы
		//у метода DataEntry производим ввод данных и в параметры передаем структуры: инициалов, даты и адреса
		d[i].DataEntry(initials, date, address);
		cout << "************************************************" << endl;
	}
}

void DataReading(Data* (&d), int& n, string fileName)
{
	//создаем поток для чтения
	ifstream reading(fileName);
	//если файл открылся
	if (reading)
	{
		//создаем временные переменные
		Initials initials;
		Date date;
		Address address;

		//считываем данные из файла, то есть колличество хранимых в нем элементов
		reading >> n;

		//Выделение памяти для массива данных
		d = new Data[n];

		//считывание данных
		for (int i = 0; i < n; i++)
		{
			reading >> initials.surname >> initials.name >> initials.patronymic;
			reading >> date.day >> date.month >> date.year;
			reading >> address.city >> address.home;

			//Добавление новые данные в элемент массива объектов класса
			d[i].DataEntry(initials, date, address);
		}
		cout << " Данные считаны!" << endl;
	}
	else
	{
		cout << "Ошибка открытия файла!" << endl;
	}

	reading.close();
}

void Print(Data* d, int n)
{
	/*
	* Так как в каждом объекте класса уже реализован print
	* мы просто проходим по циклу и для каждого элемента в массиве вызываем метод print
	*/
	for (int i = 0; i < n; i++)
	{
		cout << "Данные №" << i + 1 << endl;

		d[i].Print();
		cout << "************************************************" << endl;
	}
}

void DataChange(Data* d, int n)
{
	//временные переменные
	Initials initials;
	Date date;
	Address address;
	int _n;//переменная отвечающая за то какой элемент мы хотим изменить

	cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;//так как индекс массива начинается с нуля

	//если номер введен корректно
	if (_n >= 0 && _n<n)
	{
		//то перезаписываем данные

		cout << "Введите новую ФИО: ";
		cin >> initials.surname >> initials.name >> initials.patronymic;

		cout << "Введите новую Дату: ";
		cin >> date.day >> date.month >> date.year;

		cout << " Введите новый Адрес: ";
		cin >> address.city >> address.home;

		//Добавление новые данные в элемент массива объектов класса
		d[_n].DataEntry(initials, date, address);
	}
	else
	{
		cout << "Номер введен не верно" << endl;
	}

}

//Data* d_n (data new)массив без данных
//Data* d_o (data old) массив с данными
//int n общее колличество элементов
void Copy(Data* d_n, Data* d_o, int n)
{
	for (int i = 0; i < n; i++)
	{
		//так как мы перегрузили оператор =
		//то просто присваиваиваем значения из массива d_o массиву d_n
		d_n[i] = d_o[i];
	}
}

void AddData(Data* (&d), int& n)
{
	//временные переменные
	Initials initials;
	Date date;
	Address address;
	Data* buf = new Data[n];//временный буфферный массив
	int size = n, new_size = ++n;

	//копируем данные из массива n в массив buf
	Copy(buf, d, size);

	//выделяем память на единицу больше, так как мы добавляем новый элемент
	d = new Data[new_size];
	//копируем данные из массива buf в массив n
	Copy(d, buf, size);

	cout << "Введите новую ФИО: ";
	cin >> initials.surname >> initials.name >> initials.patronymic;

	cout << "Введите новую Дату: ";
	cin >> date.day >> date.month >> date.year;

	cout << " Введите новый Адрес: ";
	cin >> address.city >> address.home;

	//Добавление новые данные в конец элемента массива объекта класса
	//так как данные в конце массива пустые, то спокойно можно их перезаписать
	d[size].DataEntry(initials, date, address);

	cout << "Данные добавлены!" << endl;

	//очищаем динамически выделенный буферный массив
	delete[] buf;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;//переменная отвечаеющая за номер удаляемого элемента
	Data* buf = new Data[n];//временный массив

	cout << "Введите номер нужного элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n)
	{
		//копируем из текущего массива d во временный массив buf
		Copy(buf, d, n);
		int q = 0;
		n--;

		//Выделение новой памяти
		d = new Data[n];

		for (int i = 0; i <= n; i++)
		{
			//если номер элемента отличается от номера элемента который нужно удалить, то мы его сохраняем
			if (i != _n)
			{
				//перезаписываем данные из буфера в текущий массив
				d[q] = buf[i];
				q++;
			}
		}

		cout << "Данные удалены!" << endl;
	}
	else
	{
		cout << "Номер введен не верно!" << endl;
	}


	delete[] buf;
}

void SortingData(Data* d, int n)
{
	//временные переменные
	Data buf;
	int numOfSorted = 0;//счетчик колличества сортировок

	//сортировка пузырьком
	for (int i = 0; i < n; i++)//текущий
	{
		for (int j = i+1; j < n; j++)//последующий
		{
			//условие сортировки
			//если фамилия текущего элемента > фамилии последующего элемента, то меняем их местами
			if (d[i].GetInitials().surname > d[j].GetInitials().surname)
			{
				// сортировка
				//данные текущего элемента присваиваем временному элементу
				buf = d[i];
				//текущиий элемент сохраняесм как последующий
				d[i] = d[j];
				//последующий сохраняем как временный
				d[j] = buf;
				/*
				таким образом текущий и последующий элементы меняются местами
				*/
				numOfSorted++;//счетчик колличества свапов
			}
		}
	}

	cout << "Данные отсортированны!\n Колличество сортировок: " << numOfSorted << endl;
}

void SaveData(Data* d, int n, string fileName)
{
	//Создание потока для записи в файл
	ofstream record(fileName);

	//если файл открылся
	if (record)
	{
		//записываем данный о колличестве элементов
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			record << d[i].GetInitials().surname << " " << d[i].GetInitials().name << " " << d[i].GetInitials().patronymic << endl;
			record << d[i].GetDate().day << " " << d[i].GetDate().month << " " << d[i].GetDate().year << endl;
			record << d[i].GetAddress().city << " " << d[i].GetAddress().home;

			//чтобы не было отступа на следующую строку после последнего элемента в файле
			if (i < n - 1)
			{
				record << endl;
			}
		}
	}
	else
	{
		cout << "Ошибка открытия файла!" << endl;
	}

	cout << "Данные сохранены в файл: " << fileName << endl;

	record.close();
}
