#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	if (N % 2 == 0) {
		cout << "CY";
	}
	else {
		cout << "SK";
	}

	return 0;
}