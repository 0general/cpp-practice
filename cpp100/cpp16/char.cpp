#include <iostream>
using namespace std;

int main()
{
	char ch1 = 'c';
	char ch2 = 200; // char ���� -127 ~ +127

	unsigned char ch3 = 'c';
	unsigned char ch4 = 200; // unsigned char ���� 0 ~ +255 
	//unsigned -> ��ȣ�� ����, ����� ���� 

	/*
	�ƽ�Ű �ڵ� : ��ǻ�� ���� ��
	���� - 48~57
	�빮�� - 65 ~90
	�ҹ��� - 97 ~ 122	
	*/

	printf("char ch1 = %c, %d\n", ch1, ch1); // c = �ƽ�Ű �ڵ� 99
	printf("char ch2 = %c, %d\n", ch2, ch2); // ���� ���� �ʰ� �� -> ���� ���� (128-200=-72) -> �ּҹ��� -127���� 72��ŭ ������ -56 ���
	printf("char ch3 = %c, %d\n", ch3, ch3); // ���� ����
	printf("char ch4 = %c, %d\n", ch4, ch4); // ���ڸ� ���� ���, 200�� �ش��ϴ� �ƽ�Ű ���� �����Ƿ� ?���
}