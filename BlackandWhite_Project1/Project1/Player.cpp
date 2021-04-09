#include "Player.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Player::Player()
{
	deck = new Card[9]{ Card(0),Card(1),Card(2),Card(3),Card(4),Card(5),Card(6),Card(7),Card(8) };
	num_card = 9;
	fill_n(history, 9, -1);
}

void Player::randomShuffle()
{
	int nansu = 0;
	Card change;
	for (int i = 0; i < 9; i++) {		
		change = deck[i];
		nansu = rand() % 9;
		deck[i] = deck[nansu];
		deck[nansu] = change;
	}
}

Card Player::choose(int a) //a�� �迭�� �ε��� 
{
	Card ans;
	ans = deck[a];
	for (int i = a; i < num_card - 1; i++) {
		deck[i] = deck[i + 1];
	}
	history[9 - num_card] = ans.front();
	num_card -= 1;
	Card* p = new Card[num_card];
	for (int j = 0; j < num_card; j++) {
		p[j] = deck[j];
	}
	delete [] deck;
	deck = p;
	return ans;
}

int Player::search(int b) //b�� ī���� ���� front��, user�� ����ϴ� �Լ�
{
	for (int i = 0; i < num_card; i++) {
		if (deck[i].front() == b) {
			return i;
		}
		if (i == num_card - 1) {
			if (deck[i].front() != b) {
				cout << "No " << b << " in deck!!" << endl;
				return -1;  // �ٽ� search�� �Ű����� �Է¹޵��� 
			}
		}
	}
}

const void Player::printFront() const
{
	for (int i = 0; i < num_card; i++) {
		cout << "  _  " ;
	}
	cout << endl;
	for (int i = 0; i < num_card; i++) {
		cout << " |" << deck[i].front() << "| ";
	}
	cout << endl;
	for (int i = 0; i < num_card; i++) {
		cout << "  -  " ;
	}
	cout << endl;
}

const void Player::printBack() const
{
	for (int i = 0; i < num_card; i++) {
		cout << "  _  " ;
	}
	cout << endl;
	for (int i = 0; i < num_card; i++) {
		cout << " |" << deck[i].back() << "| ";
	}
	cout << endl;
	for (int i = 0; i < num_card; i++) {
		cout << "  -  " ;
	}
	cout << endl;
}

const void Player::printHistory() const
{
	for (int i = 0; i < 9; i++) {
		cout << history[i] << " ";
	}
	cout << endl;
}

Player::~Player()
{
	if (deck) {
		delete[] deck;
	}
}
