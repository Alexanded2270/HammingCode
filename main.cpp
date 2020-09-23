#include <iostream>
#include <string>
#include <vector>
using namespace std;

int pow(int base, int x) {
	int a = 1;
	for (int i = 0; i < x; ++i) {
		a *= base;
	}
	return a;
}
int interpretate(int x) {
	int s = 0;
	for (int i = 0; x; ++i, x /= 10) {
		s += x % 10 * pow(2, i);
	}
	return s;
}

int main() {
	setlocale(LC_ALL, "Russian");
	string x;
	cin >> x;
	vector <int> a(x.length());
	for (int i = 0; i < a.size(); ++i) {
		a[i] = x[i];
	}
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == 48) a[i] = 0;
		else a[i] = 1;
	}
	cout << "Начальный массив:\n";
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	//далее алгоритм поиска и замены ошибки(не открывать)
	{
		int s0 = 0, s1 = 0, s2 = 0, s3 = 0, s = 0;
		for (int i = 0; i < 15; i += 2) {
			s0 += a[i];
		}
		if (s0 % 2) s0 = 1;
		else s0 = 0;
		for (int i = 1; i < 15; i += 4) {
			s1 += a[i] + a[i + 1];
		}
		if (s1 % 2) s1 = 1;
		else s1 = 0;
		for (int i = 3; i < 15; i += 8) {
			s2 += a[i] + a[i + 1] + a[i + 2] + a[i + 3];
		}
		if (s2 % 2) s2 = 1;
		else s2 = 0;
		for (int i = 7; i < 15; i += 16) {
			s3 += a[i] + a[i + 1] + a[i + 2] + a[i + 3] + a[i + 4] + a[i + 5] + a[i + 6] + a[i + 7];
		}
		if (s3 % 2) s3 = 1;
		else s3 = 0;
		s = s0 + s1 * 10 + s2 * 100 + s3 * 1000;
		s = interpretate(s);
		cout << "Номер ошибочного элемента:\n";
		cout << s << endl;
		if (s) {
			if (a[s - 1]) a[s - 1] = 0;
			else a[s - 1] = 1;
		}
	}
	cout << "Массив с замененным ошибочным элементом:\n";
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	a.erase(a.begin(), a.begin() + 2);//удаление проверяющих битов
	a.erase(a.begin() + 1);
	a.erase(a.begin() + 4);
	cout << "Массив с удаленными проверяющими битами :\n";
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << " ";
	}
	cout << endl;

	vector <int> res;
	for (int i = 0; i < 11; ++i) {
		res.push_back(0);
		res[i] = a[i];
	}
	a.erase(a.begin(), a.begin() + 11);
	cout << "Массив с удаленными значениями:\n";
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << " ";
	}
	cout << "Результат:\n";
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
}
//111111101111000
