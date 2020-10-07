#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;
constexpr int MX = 5;

char A[MX*MX];
bitset<MX*MX> vis;
map<vector<int>, int> dp;

int f(vector<int> & v) {
	for (int i = 1; i < MX; ++i) if (v[i-1] < v[i]) return 0;
	for (int i = 0; i < MX; ++i) if (v[i] > MX) return 0;
	
	int sum = 0;
	for (int i = 0; i < MX; ++i) sum += v[i];
	if (sum == MX*MX) return 1;
	
	if (dp.find(v) != dp.end()) return dp[v];

	int ret = 0;
	for (int i = 0; i < MX; ++i)
		if (A[i*MX+v[i]] == 'A'+sum || !A[i*MX+v[i]])
			++v[i], ret += f(v), --v[i];
	return dp[v] = ret;
}

string getk(int k) {
	string ret(MX*MX, '0');

	vis.reset();
	memset(A, 0, sizeof A);
	for (int i = 0; i < MX*MX; ++i) {
		for (int j = 0; j < MX*MX; ++j) {
			if (vis[j]) continue;
			vis[j] = 1;
			
			A[i] = 'A'+j;
			dp.clear();
			vector<int> v(MX, 0);
			int tmp = f(v);
			
			if (tmp >= k) break;
			k -= tmp;
			vis[j] = 0;
		}
		ret[i] = A[i];
	}
	return ret;
}

int main() {
	if (fopen("in", "r")) freopen("in", "r", stdin), freopen("out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0);

	char c; cin >> c;
	if (c == 'N') {
		int M; cin >> M;
		cout << getk(M);
	}
	else {
		string S; cin >> S;
		int l = 0, h = 1e9;
		while (l < h) {
			int m = (l+h)/2;
			string tmp = getk(m);
			tmp < S ? l = m+1 : h = m;
		}
		cout << l;
	}
}
