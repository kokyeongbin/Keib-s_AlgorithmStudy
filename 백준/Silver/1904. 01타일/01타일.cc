#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int dp[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 15746;
	}

	cout << dp[N];

	return 0;
}