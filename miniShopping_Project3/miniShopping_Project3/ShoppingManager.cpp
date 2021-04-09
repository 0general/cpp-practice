#include "ShoppingManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#include "Product.h"



ShoppingManager::ShoppingManager(const string fn)
{

	ifstream fin(fn);
	if (!fin) {
		cout << "������ �� �� �����ϴ�." << endl;
	}
	else {
		int i = 0;
		string line;
		string token;
		vector <string> v;
		while (getline(fin,line)) {
			stringstream ss(line);
			getline(ss,token,';');
			v.push_back(token);
			getline(ss,token,'\n');
			v.push_back(token);
			Product p(v[0], stoi(v[1]));
			productList.push_back(p);
			v.clear();
		}
		
	}

}

void ShoppingManager::mainMenu()
{
	int choice;
	while (true) {
		cout << "<< INU ���ο� ���� ���� ȯ���մϴ�! >>" << endl
			<< "[1] ���� ������ ���" << endl
			<< "[2] �� ���" << endl
			<< "[3] ����" << endl;
		cout << "�Է� : ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			managerMode();
			break;
		case 2:
			customerMode();
			break;
		case 3:
			return;
		default:
			cout << "�߸��� �Է��Դϴ�.";
			break;
		}
	}
	
}

void ShoppingManager::managerMode()
{
	int pw;
	int select;
	cout << endl <<"������ ��й�ȣ�� �Է��ϼ���(���� ȭ������ ���ư����� -1 �Է�) : ";
	cin >> pw;
	cout << endl;
	if (pw == -1) {
		return;
	}
	else if (pw == 1234) {
		while (true) {
			cout << endl << "< ���� ������ ���> " << endl;
			cout << "[1] ��ǰ�߰�" << endl
				<< "[2] ��ǰ����" << endl
				<< "[3] ��� ��ǰ ���" << endl
				<< "[4] ���ư���" << endl;
			cout << "�Է� : ";
			cin >> select;
			cout << endl;
			switch (select)
			{
			case 1:
				addProduct();
				cout << endl;
				break;
			case 2:
				deleteProduct();
				cout << endl;
				break;
			case 3:
				print(productList);
				cout << endl << "�� " << productList.size() << "������ ��ǰ" << endl;
				break;
			case 4:
				return;
			default:
				cout << "�߸��� �Է��Դϴ�.";
				break;
			}
		}		
	}
	else {
		cout << "��й�ȣ�� Ʋ���ϴ�!"<< endl;
		managerMode();
	}
}

void ShoppingManager::customerMode()
{
	int choose;
	while (true) {
		cout << endl << "< �� ��� >" << endl;
		cout << "[1] ��ǰ ����" << endl
			<< "[2] ��ǰ �˻�" << endl
			<< "[3] ��ٱ��� ���" << endl
			<< "[4] ���ư���" << endl;
		cout << "�Է� : ";
		cin >> choose;
		cout << endl;
		switch (choose)
		{
		case 1:
			print(productList);
			cout << endl << "�� " << productList.size() << "������ ��ǰ" << endl;
			break;
		case 2:
			search();
			break;
		case 3 :
			cartMode();
			break;
		case 4 : 
			return;
		default:
			cout << "�߸��� �Է��Դϴ�. " << endl;
			break;
		}
	}

}

void ShoppingManager::addProduct()
{
	Product pp("", 0);
	cout << "���ο� ��ǰ�� �߰��մϴ�. ��ǰ �̸� �Է� �� no�� �Է��ϸ� ���������ϴ�." << endl;
	cout << endl;
	while (true) {
		cin >> pp;
		if (pp.getName() != "no") {
			for (int i = 0; i < productList.size(); i++) {
				if (productList[i].getName() == pp.getName()) {
					cout << "�̹� �����ϴ� ��ǰ�Դϴ�." << endl;
					cout << endl;
					break;
				}
				else if (i == productList.size() - 1) {
					productList.push_back(pp);
					cout << pp.getName() << "��(��) ��Ͽ� ����߽��ϴ�." << endl;
					cout << endl;
					break;
				}
				else {
					continue;
				}
			}
		}
		else {
			cout << endl;
			return;
		}		
		continue;
	}

	
}

void ShoppingManager::deleteProduct()
{
	string dp;
	vector<Product>::iterator it;
	
	cout << "�����Ͻ� ��ǰ�� �̸��� �Է��ϼ��� : ";
	cin.ignore();
	getline(cin,dp);
	for (it = productList.begin(); it != productList.end();it++) {
		Product n = *it;
		if (n.getName() == dp) {
			it = productList.erase(it);
			cout << n.getName() << "��(��) �����մϴ�. " << endl;
			return;
		}
		else if (it == productList.end() - 1) {
			cout << "�Է��Ͻ� ��ǰ�� ��Ͽ� �����ϴ�. " << endl;
			return;
		}
	}

}

void ShoppingManager::print(vector<Product> pList)
{
	for (int i = 0; i < pList.size(); i++) {
		cout << pList[i];
	}
}

void ShoppingManager::search()
{
	string sn;
	cout << "��ǰ���� �Է��ϼ��� : ";
	cin.ignore();
	getline(cin ,sn);
	for (int j = 0; j < productList.size(); j++) {
		if (productList[j].getName() == sn) {
			cout << productList[j] << endl;
			return;
		}
		else if (j == productList.size()-1) {
			cout << "�Է��Ͻ� ��ǰ�� ���� ��ϵǾ� ���� �ʽ��ϴ�." << endl;
			return;
		}
	}
}

void ShoppingManager::cartMode()
{
	vector<Product> cart;
	int cartin;
	while (true) {
		cout << endl << "< ��ٱ��� ��� >" << endl;
		cout << "[1] ��ǰ����" << endl
			<< "[2] ��ٱ��Ͽ� ���" << endl
			<< "[3] ��ٱ��� ���" << endl
			<< "[4] ����ϱ�" << endl;
		cout << "�Է� : ";
		cin >> cartin;
		cout << endl;
		switch (cartin)
		{
		case 1:
			print(productList);
			cout << endl << "�� " << productList.size() << "������ ��ǰ" << endl;
			break;
		case 2:
		{
			addToCart(cart);
			break;
		}
		case 3 :
			print(cart);
			cout << endl << "�� " << cart.size()<<"������ ��ǰ" << endl;
			break;
		case 4 :
			calculate(cart);
			cout << "��ٱ��� ��带 �����մϴ�." << endl << endl;
			return;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}
	}

}

vector<Product> ShoppingManager::addToCart(vector<Product>&cart)
{
	string cn;
	int cprice;
	int yang;
	cin.ignore();
	while (true) {
		cout << "�����ϰ��� �ϴ� ��ǰ �̸� �Է�(��ٱ��� ��� ����� no �Է�) : ";		
		getline(cin, cn);
		if (cn != "no") {
			for (int j = 0; j < productList.size(); j++) {
				if (productList[j].getName() == cn) {
					cout << "���� ���� �Է�(" << cn << "�� ���� ��� : "
						<< productList[j].getStock() << ") : ";
					cin >> yang;
					cin.ignore();
					cprice = productList[j].getPrice();
					if (yang <= productList[j].getStock()) {
						Product cp(cn,cprice,yang);
						if (cart.size() != 0) {
							for (int q = 0; q < cart.size(); q++) {
								if (cart[q].getName() == cn) {
									cart[q].setCartStock(yang);
									break;
								}
								else if (q == cart.size() - 1) {
									cart.push_back(cp);
									break;
								}
							}
						}
						else {
							cart.push_back(cp);
						}

						productList[j].setStock(yang);
						cout << cn << " " << yang << " ���� ��ٱ��Ͽ� ��ҽ��ϴ�." << endl;
						cout << endl;
					}
					else {
						cout << "���� �� �ִ� ������ �ʰ��߽��ϴ�. " << endl << endl;
					}
					break;
				}
				else if (j == productList.size() - 1) {
					cout << "�Է��Ͻ� ��ǰ�� ���� ��ϵǾ� ���� �ʽ��ϴ�." << endl;
					break;
				}
			}
		}
		else {
			break;
		}
	}
	return vector<Product>();
}

void ShoppingManager::calculate(const vector<Product> &cart)
{
	int sum = 0;
	if (cart.size() != 0) {
		for (int k = 0; k < cart.size(); k++) {
			int gap = 0;
			cout << cart[k];
			gap += cart[k].getPrice() * cart[k].getStock();
			sum += gap;
		}
		cout << endl << "�� " << cart.size() << "������ ��ǰ" << endl;
		cout << "�� " << sum << "�� ���� �Ϸ�Ǿ����ϴ�." << endl;
	}
	else {
		cout << "��ٱ��Ͽ� �ƹ��͵� �����ϴ�." << endl;
		return;
	}
}
