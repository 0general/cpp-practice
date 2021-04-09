#include "Product.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

Product::Product(string n, int p, int s) : name(n),price(p),stock(s) {}

string Product::getName() const
{
	return name;
}

int Product::getStock() const
{
	return stock;
}

int Product::getPrice() const
{
	return price;
}

void Product::setStock(int su)
{
	stock -= su;
}

void Product::setCartStock(int su)
{
	stock += su;
}


istream& operator>>(istream& ins, Product& p)
{
	cout << "��ǰ �̸� �Է� : ";
	ins.ignore();
	getline(ins, p.name);	
	if (p.name != "no") {
		cout << "��ǰ ���� �Է� : ";
		ins >> p.price;
	}
	else {
		cout << "���ο� ��ǰ �߰� ����." << endl;
	}
	return ins;
}

ostream& operator<<(ostream& stream, const Product& p)
{
	// cout.setf(ios::left);
	stream << left << "��ǰ�� : " << setw(20) << p.name;
	// cout.setf(ios::right);
	stream.fill(' ');
	stream << right << " ���� : " << setw(12)<< p.price << "�� ";
	stream << " ���/���� : " << setw(4)<<p.stock << "��" << endl;

	return stream;
}
