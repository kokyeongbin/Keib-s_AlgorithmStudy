#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int K, M, N;
	cin >> K >> M >> N;

	int rst;
	rst = M * K - N;
	if (rst >= 0)
		cout << rst;
	else
		cout << "0";
	
	return 0;
}