#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	round = 0;
	comp_first = true;
	user_wins = 0;
	comp_wins = 0;
}

//computer�� ���� index�� ������ �޴� k
int k;
//user�� ���� ī�� �ε���
int uk;

Card cans, uans; //������ ī�� �����
void Game::play()
{
	cout << "Black and White Game!!" << endl;
	cout << "computer is shuffling his card..." << endl;
	computer.randomShuffle();
	cout << endl;
	round = 1;
	for (int i = 1; i <= 9; i++) {
		cout << "=================================================================" << endl;
		cout << "Round : " << round << endl;
		cout << "=================================================================" << endl;
		cout << "<computer card>" << endl;
		computer.printBack();
		cout << "<user card>" << endl;
		user.printFront();
		cout << endl;
		
		advanceRound();

		round++;
	}
	cout << endl;
	cout << "=================================================================" << endl;
	cout << "All rounds has ended. " << endl;
	cout << "=================================================================" << endl;
	cout << "user won " << user_wins << " times." << endl;
	cout << "computer won " << comp_wins << " times." << endl;
	if (user_wins > comp_wins) {
		cout << "Congratulations! You won! :)" << endl;
	}
	else if (user_wins == comp_wins) {
		cout << "You tied! Try again!" << endl;
	}
	else {
		cout << "I'm sorry but you lost. Try again! " << endl;
	}
	cout << endl;
	cout << "user history     : ";
	user.printHistory();
	cout << endl;

	cout << "computer history : ";
	computer.printHistory();
	cout << endl;
}

void Game::advanceRound()
{
	//com_first�� true�� computer's turn!
	if (comp_first == true) {
		//computer�� ���� ����

		cout << "computer's turn!" << endl;
		k = rand() % (9 + 1 - round);
		cans = computer.choose(k);
		cout << "                  _ " << endl;
		cout << "computer chose : |" << cans.back() << "|" << endl;
		cout << "                  - " << endl;
		cout << endl;


		//user�� ���� ����

		cout << "Your turn!" << endl;
		//user�� search�Լ��� ����Ѵ�.

		//search�� ������ user�� ���õ� index�� ã�´�.
		//search���� -1�̶�� �ٽ� �����ؾ� �ϹǷ� while�� �ȿ� �ִ´�. 
		while (true) {
			cout << "Which Card will you choose? ";
			int find;
			cin >> find;
			uk = user.search(find);
			if (uk != -1) break;
		}
		cout << endl;
		uans = user.choose(uk);
		cout << "              _ " << endl;
		cout << "user chose : |" << uans.front() << "|" << endl;
		cout << "              - " << endl;
	}
	else {
		//user�� ���� ����

		cout << "Your turn!" << endl;
		//user�� search�Լ��� ����Ѵ�.

		//search�� ������ user�� ���õ� index�� ã�´�.
		//search���� -1�̶�� �ٽ� �����ؾ� �ϹǷ� while�� �ȿ� �ִ´�. 
		while (true) {
			cout << "Which Card will you choose? ";
			int find;
			cin >> find;
			uk = user.search(find);
			if (uk != -1) break;
		}
		cout << endl;
		uans = user.choose(uk);
		cout << "              _ " << endl;
		cout << "user chose : |" << uans.front() << "|" << endl;
		cout << "              - " << endl;


		//computer�� ���� ����

		cout << "computer's turn!" << endl;
		//computer�� ���� ���� ������ �޴� k
		k = rand() % (9 + 1 - round);
		cans = computer.choose(k);
		cout << "                  _ " << endl;
		cout << "computer chose : |" << cans.back() << "|" << endl;
		cout << "                  - " << endl;
		cout << endl;
	}

	if (cans.front() > uans.front()) {
		comp_wins += 1;
		cout << ">>>>>> computer won!" << endl;
		cout << endl;
		comp_first = true;
	}
	else if (cans.front() == uans.front()) {
		cout << ">>>>>> It's tied! No one has earned a point." << endl;
		cout << endl;
	}
	else {
		user_wins += 1;
		cout << ">>>>>> user won!" << endl;
		cout << endl;
		comp_first = false;
	}
}
