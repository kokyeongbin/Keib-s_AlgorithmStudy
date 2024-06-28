#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector <bool> isPrime;
vector <int> prime;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	isPrime.resize(n + 1, true);

	for (int i = 2; i * i <= n; i++) {
		for (int j = i * 2; j <= n; j += i) {
			isPrime[j] = false;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) prime.push_back(i);
	}

	int start = 0, end = 0, sum = 0;
	while (1) {
		if (sum > n) sum -= prime[start++];
		else if (end == prime.size()) break;
		else sum += prime[end++];

		if (sum == n) ans++;
	}

	cout << ans << "\n";
	return 0;
}