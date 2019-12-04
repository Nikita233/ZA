// ConsoleApplication39.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <tchar.h>
using namespace std;

#define cls system("cls")
#define pause system("pause")
#define rus setlocale(LC_ALL, "Russian");


int customFunct(int param, int mod) {
	return ((param * param + 1) % mod);
}

int GCD(int x, int y)
{
	if (x == 0)
		return y;
	if (y == 0)
		return x;
	x = x % y;
	return GCD(y, x);
}

int PollardRho(int number) {
	int a = 2, b = 2, tmp;
	while (true)
	{
		a = customFunct(a, number);
		b = customFunct(customFunct(b, number), number);
		tmp = GCD(abs(b - a), number);
		if (tmp > 1)
			break;
	}
	return tmp;

}


int _tmain(int argc, _TCHAR* argv[]) {
	rus;
	int n, m1, m2, m3;

	cout << "Enter number: ";

	cin >> n;
	m1 = PollardRho(n);

	n = n / m1;
	m2 = PollardRho(n);

	n = n / m2;
	m3 = PollardRho(n);

	cout << "Мн.1 : " << m1 << endl;
	cout << "Мн.2 : " << m2 << endl;
	cout << "Мн.3 : " << m3 << endl;

	pause;
	cout << "Завершение работы...\n";
	return 0;
}