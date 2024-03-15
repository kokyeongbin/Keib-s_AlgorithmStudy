#include <iostream>
#define MOD 10007
using namespace std;

typedef long long ll;
int N, K;
ll dp[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> K;
	dp[0][0] = 1; dp[1][0] = 1; dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) dp[i][0] = 1;
			else if (j == i) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << dp[N][K];

	return 0;
}