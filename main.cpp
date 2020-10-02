#include <iostream>
#include <string>
#include <vector>
using namespace std;

int binpow(int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow(a, n - 1) * a;
	else {
		int b = binpow(a, n / 2);
		return b * b;
	}
}
int interpretate(int x) {
	int s = 0;
	for (int i = 0; x; ++i, x /= 10) {
		s += (x % 10) * binpow(2, i);
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
	vector <int> res;
	int kkk = 0;
	while (a.size() >= 15) {
		//далее алгоритм поиска и замены ошибки
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
			if (s) {
				if (a[s - 1]) a[s - 1] = 0;
				else a[s - 1] = 1;
			}
		}
		a.erase(a.begin(), a.begin() + 2);//удаление проверяющих битов
		a.erase(a.begin() + 1);
		a.erase(a.begin() + 4);
		int hhh = 0;
		for (int i = 11 * kkk; i < 11 * kkk + 11; ++i) {
			res.push_back(5);
			res[i] = a[hhh];
			hhh++;
		}
		kkk++;
		a.erase(a.begin(), a.begin() + 11);
	}
	vector <int> ansres;
	int ggg = 0;
	while (res.size() >= 8) {
		int ans = 0;
		for (int i = 0; i < 8; ++i) {
			if (res[i]) {
				ans += binpow(10, 7 - i);
			}
		}
		ansres.push_back(0);
		ansres[ggg] = interpretate(ans);
		ggg++;
		res.erase(res.begin(), res.begin() + 8);
	}
	string ascii[256] = { "err_1", "err_2", "err_3", "err_4", "err_5", "err_6", "err_7", "err_8", "err_9", "err_10", "err_11", "err_12", "err_13", "err_14", "err_15", "err_16", "err_17", "err_18", "err_19", "err_20", "err_21", "err_22", "err_23", "err_24", "err_25", "err_26", "err_27", "err_28", "err_29", "err_30", "err_31", " ", "!", "kavichki", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".", "/", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", ":", ";", "<", "=", ">", "?", "@", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "[", "_palka_", "]", "^", "_", "_ydareniye_", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "{", "|", "}", "~", "err_127", "err_128", "err_129", "err_130", "err_131", "err_132", "err_133", "err_134", "err_135", "err_136", "err_137", "err_138", "err_139", "err_140", "err_141", "err_142", "err_143", "err_144", "err_145", "err_146", "err_147", "err_148", "err_149", "err_150", "err_151", "err_152", "err_153", "err_154", "err_155", "err_156", "err_157", "err_158", "err_159", "err_160", "err_161", "err_162", "err_163", "err_164", "err_165", "err_166", "err_167", "err_168", "err_169", "err_170", "err_171", "err_172", "err_173", "err_174", "err_175", "err_176", "err_177", "err_178", "err_179", "err_180", "err_181", "err_182", "err_183", "err_184", "err_185", "err_186", "err_187", "err_188", "err_189", "err_190", "err_191", "А", "Б", "В", "Г", "Д", "Е", "Ж", "З", "И", "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э", "Ю", "Я", "а", "б", "в", "г", "д", "е", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я" };
	for (int i = 0; i < ansres.size(); ++i) {
		cout << ascii[ansres[i] - 1];
	}
}
