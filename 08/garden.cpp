#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MX = 1e6+5;

int p2[MX] = { 1 };

int main() {
	if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N, M; cin >> N >> M;
	string S; cin >> S;

	for (int i = 0; i < N; ++i) p2[i+1] = 2*p2[i]%M;

	int ans = 1, cnt = 0, l = 0, h = 0;
	for (int i = 0; i < N; ++i) {
		if (S[i] == 'P') {
			int a = min(cnt-1, l), b = max(cnt-1, h);
			if (abs(b-a) == 1) (ans += p2[(N-i-1)/2]+p2[(N-i)/2]-1) %= M;
			else if (abs(b-a) == 2) (ans += p2[(N-i-(cnt != a))/2]) %= M;
		}
		cnt += (S[i] == 'P' ? 1 : -1);
		l = min(cnt, l), h = max(cnt, h);
	}
	cout << ans;
}
