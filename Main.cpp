#include"CPI.h"

int main() {
	char in[20], po[20];
	cout << "Enter INFIX: ";
	cin >> in;
	convertPI(in, po);
	print(po);
	system("PAUSE");
	return 0;
}
