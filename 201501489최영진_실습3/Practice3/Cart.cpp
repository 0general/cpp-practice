#include <iostream>
#include <string>
using namespace std;
#include "Cart.h"
#include "Food.h"

Cart::Cart(int n) {
	this->n = n;
	content = new Food[n];
	input();
}
Cart::Cart(const Cart& c) {
	this->n = c.n;
	this->content = new Food[n];
	for (int i = 0; i < this->n; i++) {
		this->content[i] = c.content[i];
	}

}
Cart::~Cart() {
	delete [] content;
}
int Cart::getN() { return n; }
void Cart::input() {
	cout << getN() << "���� ǰ���� �Է��ϼ���...(���� : ǰ�� �ܰ�)" << endl;
	for (int i = 0; i < getN(); i++) {
		string cname;
		double cprice;
		cout << "Food" << i + 1 << " >> ";
		cin >> cname >> cprice;
		content[i].setName(cname);
		content[i].setPrice(cprice);
	}
}
void Cart::print() {
	for (int i = 0; i < getN() ; i++) {
		cout << i + 1 << "��° ǰ�� : " << content[i].getName() << " "
			<< content[i].getQuantity() <<" * "<< content[i].getPrice()<<" = " 
			<<content[i].getTotal() << endl;
	}
}
void Cart::updateQuantity() {
	cout << endl;
	int x;
	for (int i = 0; i < getN(); i++) {
		cout << content[i].getName() << " : ������ �Է� >> ";
		cin >> x;
		content[i].setQuantity(x);
	}
}
double Cart::compute() {
	double hap = 0;
	for (int i = 0; i < getN(); i++) {
		hap += content[i].getTotal();
	}
	return hap;
}
