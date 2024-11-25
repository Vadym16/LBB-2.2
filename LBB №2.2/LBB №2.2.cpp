#include <iostream>
#include <string>

using namespace std;

string plus_prob(string line);
int parnist(int a);
void view(uint16_t a);
void shufr(char c, int row, int pos);


int main()
{
	setlocale(LC_ALL, "ukr");

	string txt[4] = {
		"First line",
		"Second line",
		"Third line",
		"Fourth line"
	};

	for (int i = 0; i < 4; i++) {
		txt[i] = plus_prob(txt[i]);
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 16; j++) {
			shufr(txt[i][j], i, j);
		}
	}

}

string plus_prob(string line) {
	while (line.length() < 16) {
		line += ' ';
	}
	return line;
}

int parnist(int a) {
	int par = 0;
	while (a) {
		par ^= (a & 1);
		a >>= 1;
	}
	return par;
}

void view(uint16_t a) {
	for (int i = 16; i >= 0; i--) {
		cout << ((a >> i) & 1);
	}
	cout << endl;
}

void shufr(char c, int row, int pos) {
	int ascii = static_cast<int>(c);
	int up = (ascii >> 4) & 0xF;
	int low = ascii & 0xF;

	int row_b = row & 0x3;
	int pos_b = pos & 0xF;
	int par1 = parnist(row_b << 2 | up);
	int par2 = parnist(pos_b << 4 | low);

	uint16_t b1 = (row_b << 6) | (up << 2) | par1;
	uint16_t b2 = (low << 8) | (pos_b << 4) | par2;

	cout << "Буква: " << c << endl;
	cout << "Байт 1: ";
	view(b1);
	cout << "Байт 2: ";
	view(b2);

}