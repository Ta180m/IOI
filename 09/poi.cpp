#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MX = 2005;

bool B[MX][MX];
int pt[MX], sc[MX], sv[MX], rk[MX];

int main() {
	if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N, T, P; cin >> N >> T >> P;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < T; ++j) cin >> B[i][j];
	}

	for (int i = 0; i < T; ++i) {
		pt[i] = N;
		for (int j = 0; j < N; ++j) pt[i] -= B[j][i];
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < T; ++j)
			if (B[i][j]) sc[i] += pt[j], ++sv[i];
	
	for (int i = 0; i < N; ++i) rk[i] = i;
	
	sort(rk, rk+N, [&](int a, int b) {
		if (sc[a] == sc[b]) {
			if (sv[a] == sv[b]) return a < b;
			return sv[a] > sv[b];
		}
		return sc[a] > sc[b];
	});

	for (int i = 0; i < N; ++i) {
		if (rk[i] == P-1) {
			cout << sc[rk[i]] << ' ' << i+1;
			return 0;
		}
	}
}