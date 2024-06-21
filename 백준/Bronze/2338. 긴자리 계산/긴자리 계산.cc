#include <iostream>
#include <cstring>
using namespace std;

int bigger(char* a, char* b) {
	if (strlen(a) > strlen(b))
		return 1;
	else if (strlen(a) < strlen(b))
		return 0;
	else {
		for (int i = 0; i < strlen(a); i++) {
			if (a[i] > b[i])
				return 1;
			else if (a[i] < b[i])
				return 0;
		}
	}
	return 2;
}

void add(char* a, char* b) {
	int num[1010] = { 0 };
	int i = strlen(a) - 1;

	for (int j = strlen(b) - 1; j >= 0; j--) {
		if (i >= 0) {
			num[i] = (a[i] - '0') + (b[j] - '0');
		}
		i--;
	}

	for (; i >= 0; i--) {
		num[i] = a[i] - '0';
	}

	for (int i = strlen(a) - 1; i > 0; i--) {
		if (num[i] > 9) {
			num[i] -= 10;
			num[i - 1]++;
		}
	}

	for (int i = 0; i < strlen(a); i++) {
		cout << num[i];
	}
	cout << "\n";
}

void subtract(char* a, char* b) {
	int num[1010] = { 0 };
	int i = strlen(a) - 1;
	bool check = false;

	for (int j = strlen(b) - 1; j >= 0; j--) {
		if (i >= 0) {
			num[i] = (a[i] - '0') - (b[j] - '0');
		}
		i--;
	}

	for (; i >= 0; i--) {
		num[i] = a[i] - '0';
	}

	for (i = strlen(a) - 1; i > 0; i--) {
		if (num[i] < 0) {
			num[i] += 10;
			num[i - 1]--;
		}
	}

	for (i = 0; i < strlen(a); i++) {
		if (num[i] != 0) {
			check = true;
		}
	}

	if (!check) {
		cout << 0;
	}
	else {
		for (i = 0; num[i] == 0; i++);
		for (; i < strlen(a); i++) {
			cout << num[i];
		}
	}
	cout << "\n";
}

void multiple(char* a, char* b) {
	int num[2020] = { 0 };
	bool check = false;

	for (int i = 0; i < strlen(a); i++) {
		for (int j = 0; j < strlen(b); j++) {
			num[i + j] += (a[i] - '0') * (b[j] - '0');
		}
	}

	for (int i = strlen(a) + strlen(b) - 1; i > 0; i--) {
		num[i - 1] += num[i] / 10;
		num[i] = num[i] % 10;
	}

	for (int i = 0; i < strlen(a); i++) {
		if (num[i] != 0) {
			check = true;
		}
	}

	if (!check) {
		cout << 0;
	}
	else {
		for (int i = 0; i < strlen(a) + strlen(b) - 1; i++) {
			cout << num[i];
		}
	}
}

int main(void) {
	char a[1010];
	char b[1010];
	int check_1 = 0;
	int check_2 = 0;

	cin >> a >> b;

	if (a[0] == '-')
		check_1 = 1;
	if (b[0] == '-')
		check_2 = 1;

	if (check_1 + check_2 == 0) {
		if (bigger(a + check_1, b + check_2) != 0) {
			add(a + check_1, b + check_2);
		}
		else {
			add(b + check_2, a + check_1);
		}
	}
	else if (check_1 + check_2 == 2) {
		if (bigger(a + check_1, b + check_2) != 0) {
			cout << "-";
			add(a + check_1, b + check_2);
		}
		else {
			cout << "-";
			add(b + check_2, a + check_1);
		}
	}
	else {
		if (check_1 == 1 && check_2 == 0) {
			if (bigger(a + check_1, b + check_2) == 1) {
				cout << "-";
				subtract(a + check_1, b + check_2);
			}
			else {
				subtract(b + check_2, a + check_1);
			}
		}
		else if (check_1 == 0 && check_2 == 1) {
			if (bigger(a + check_1, b + check_2) != 0) {
				subtract(a + check_1, b + check_2);
			}
			else {
				cout << "-";
				subtract(b + check_2, a + check_1);
			}
		}
	}

	if (check_1 + check_2 == 0) {
		if (bigger(a + check_1, b + check_2) != 0) {
			subtract(a + check_1, b + check_2);
		}
		else {
			cout << "-";
			subtract(b + check_2, a + check_1);
		}
	}
	else if (check_1 + check_2 == 2) {
		if (bigger(a + check_1, b + check_2) == 1) {
			cout << "-";
			subtract(a + check_1, b + check_2);
		}
		else {
			subtract(b + check_2, a + check_1);
		}
	}
	else {
		if (check_1 == 1 && check_2 == 0) {
			if (bigger(a + check_1, b + check_2) != 0) {
				cout << "-";
				add(a + check_1, b + check_2);
			}
			else {
				cout << "-";
				add(b + check_2, a + check_1);
			}
		}
		else if (check_1 == 0 && check_2 == 1) {
			if (bigger(a + check_1, b + check_2) != 0) {
				add(a + check_1, b + check_2);
			}
			else {
				add(b + check_2, a + check_1);
			}
		}
	}

	if (check_1 + check_2 == 1 && a[0] != '0' && b[0] != '0') {
		cout << "-";
	}
	multiple(a + check_1, b + check_2);

	return 0;
}