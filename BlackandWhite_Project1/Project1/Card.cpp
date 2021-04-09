#include "Card.h"
#include <iostream>
using namespace std;

Card::Card() {
	color = 'b';
	number = 0;
}

Card::Card(int n) 
{ 
	//n�� ī�� �ո��� ����
	number = n;
	//n�� ¦���� color�� b, n�� Ȧ���� color�� w
	if (n % 2 == 0) {
		color = 'b';
	}
	else {
		color = 'w';
	}
}

const int Card::front() const
{
	//getNumber()�� �ش��ϴ� getter�Լ�
	return number;
}

const char Card::back() const
{
	//getColor()�� �ش��ϴ� getter�Լ�
	return color;
}
