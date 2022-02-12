#include "Data.h"//заголовочный файл с прототипом класса
//реализация конструктора по умолчанию (без параметров)
//создается просто проинициализированный но пустой объект
Data::Data()
{
    initials.surname = "";
    initials.name = "";
    initials.patronymic = "";

    date.day = 0;
    date.month = 0;
    date.year = 0; 

    address.city = "";
    address.home = 0;
}

//конструктор с параметрами

Data::Data(Initials initials_, Date date_, Address address_)
{
    //присваиваиваем полям класса входные данные

    initials.surname = initials_.surname;
    initials.name = initials_.name;
    initials.patronymic = initials_.patronymic;

    date.day = date_.day;
    date.month = date_.month;
    date.year = date_.year;

    address.city = address_.city;
    address.home = address_.home;
}

//так как нет динамически выделяемой памяти то реализовывать деструктор не нужно
Data::~Data()
{
}

//Вывод в консоль информацию о текущум объекте
void Data::Print()
{
    cout << "ФИО: " << initials.surname << " " << initials.name << " " << initials.patronymic << endl;
    cout << "Дата: " << date.day << " " << date.month << " " << date.year << endl;
    cout << "Адрес: " << address.city << " " << address.home  << endl;
}
 //Ввод данных (аналогично конструктору с параметрами)
void Data::DataEntry(Initials initials_, Date date_, Address address_)
{
    initials.surname = initials_.surname;
    initials.name = initials_.name;
    initials.patronymic = initials_.patronymic;

    date.day = date_.day;
    date.month = date_.month;
    date.year = date_.year;

    address.city = address_.city;
    address.home = address_.home;
}

Data& Data::operator=(Data d_o)
{
    this->initials.surname = d_o.initials.surname;
    this->initials.name = d_o.initials.name;
    this->initials.patronymic = d_o.initials.patronymic;

    this->date.day = d_o.date.day;
    this->date.month = d_o.date.month;
    this->date.year = d_o.date.year;

    this->address.city = d_o.address.city;
    this->address.home = d_o.address.home;

    return *this;
}
