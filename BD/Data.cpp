#include "Data.h"//������������ ���� � ���������� ������
//���������� ������������ �� ��������� (��� ����������)
//��������� ������ ��������������������� �� ������ ������
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

//����������� � �����������

Data::Data(Initials initials_, Date date_, Address address_)
{
    //�������������� ����� ������ ������� ������

    initials.surname = initials_.surname;
    initials.name = initials_.name;
    initials.patronymic = initials_.patronymic;

    date.day = date_.day;
    date.month = date_.month;
    date.year = date_.year;

    address.city = address_.city;
    address.home = address_.home;
}

//��� ��� ��� ����������� ���������� ������ �� ������������� ���������� �� �����
Data::~Data()
{
}

//����� � ������� ���������� � ������� �������
void Data::Print()
{
    cout << "���: " << initials.surname << " " << initials.name << " " << initials.patronymic << endl;
    cout << "����: " << date.day << " " << date.month << " " << date.year << endl;
    cout << "�����: " << address.city << " " << address.home  << endl;
}
 //���� ������ (���������� ������������ � �����������)
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
