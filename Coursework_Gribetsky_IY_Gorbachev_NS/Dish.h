#pragma once
#include <iostream>
#include <string>

using namespace std;
struct dish_info		// ��������� ��� �������� ���� ���������� ��� ������������ �����
{
	string dish;		// �������� �����
	int price = 0;			// ��� ���������
	string dish_type;	// ��� �����
	int weight = 0;			// ��� �����
	string restaurant;  // ��������, � ������� ��� ������
};

// ���������� ���������� ���������

bool operator == (const dish_info& s_1, const dish_info& s_2);
// ��� ��������� ������ ���� ����������

bool operator != (const dish_info& s_1, const dish_info& s_2);
// ���� �� 1 �������� � ���� ����������

bool operator > (const dish_info& s_1, const dish_info& s_2); 
// ���� ��� ��������������� �������, �� ��������� ���� � ��������� �������: �������� -> ��������� -> ��� -> ��� -> ��������

bool operator < (const dish_info& s_1, const dish_info& s_2);
bool operator <=(const dish_info& s_1, const dish_info& s_2);
bool operator >=(const dish_info& s_1, const dish_info& s_2);

// ���������� ���������� ����� � ������ � ������

ostream& operator<< (ostream& out, const dish_info& d);
// ������: "cabbage pie - 100 rubles - baked products - 350 gramms - Teremok auto"

istream& operator>> (istream& in, dish_info& d);
// ��� ������ ��������� ������ �� �����: dish_name, price, dish_type, weight, restaurant_name

void clear(string& s);
