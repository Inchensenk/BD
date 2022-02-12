#pragma once
#include <iostream>//����� �����-������
#include <string>//������
#include <fstream>//������ � �������� ������ ������ � ����� � � ����
#include <Windows.h>//�������������� �������

using namespace std;//������������ ���� ������������ ������ �����-������

/*
	������:
	1. ��� 
	2. ����
	3. �����
*/

//���
struct Initials
{
	string surname,//������� 
		name,//���
		patronymic;//��������
};

//����
struct Date
{
	int day,//���� 
		month,//�����
		year;//���
};

//�����
struct Address
{
	string city;
	int home;
};

//�������� ������
class Data
{
	//�������� ����� ������ (���� ������)
private:
	Initials initials;
	Date date;
	Address address;

	//�������� ����� ������
public:
	//������������ ������ ������
	Data(); //����������� �� ���������. ������� ������ ������
	Data(Initials initials_, Date date_, Address address_);//����������� � �����������. ������� ������ ������ � �����������
	~Data();//����������. �������� ������

	//�� ������������ ������� ������ (����� ��� ���������� ������ ������)
	//����� ������ � �������
	void Print();
	//���� ������
	void DataEntry(Initials initials_, Date date_, Address address_);
	//����� ������ (�����) �� ������
	Initials GetInitials() { return initials; };
	Date GetDate() { return date; };
	Address GetAddress() { return address; };

	//���������� ��������� =
	Data& operator = (Data d_o);
};