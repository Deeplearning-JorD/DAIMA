#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef pair<int, int> pint;
typedef tuple<int, int, int> tint;

const int N = 8e5 + 5;
const int K = 20 + 2;
const int C = 10 + 2;

namespace sam {
	int ch[N][C], pa[N], len[N];
	int isEnd[N], posToEnd[N];
	int idx = 1, pre = 1;

	void insert(int c, int id) {
		int p = pre, np = ++idx;
		pre = np;
		isEnd[np] = id;
		posToEnd[id] = np;
		len[np] = len[p] + 1;
		while (p && ch[p][c] == 0)
			ch[p][c] = np, p = pa[p];

		if (p == 0)
			pa[np] = 1;
		else {
			int q = ch[p][c];
			if (len[q] == len[p] + 1)
				pa[np] = q;
			else {
				int nq = ++idx;
				len[nq] = len[p] + 1;
				memcpy(ch[nq], ch[q], sizeof(ch[q]));
				pa[nq] = pa[q];
				pa[q] = pa[np] = nq;
				while (p && ch[p][c] == q)
					ch[p][c] = nq, p = pa[p];
			}
		}
	}

	void build_tree(vector<int> a[]) {
		for (int i = 1; i <= idx; i++)
			if (pa[i])
				a[pa[i]].push_back(i);
	}
}; // namespace sam

ll ans = 0;

namespace vtree {
	vector<int> a[N], va[N]; // va 存放虚树结果，只有从根往下的边，无反向边

	int dfnL[N], dfnR[N], dep[N], anc[N][K];
	int tms;

	void dfs(int u, int pa) {
		dfnL[u] = ++tms;
		dep[u] = dep[pa] + 1;
		anc[u][0] = pa;
		for (int i = 1; i < K; i++)
			anc[u][i] = anc[anc[u][i - 1]][i - 1];

		for (auto v: a[u])
			if (v != pa)
				dfs(v, u);
		dfnR[u] = tms;
	}

	int getLCA(int u, int v) {
		if (dep[u] < dep[v]) swap(u, v);
		for (int i = K - 1; i >= 0; i--)
			if (dep[anc[u][i]] >= dep[v])
				u = anc[u][i];
		if (u == v) return u;
		for (int i = K - 1; i >= 0; i--)
			if (anc[u][i] != anc[v][i])
				u = anc[u][i], v = anc[v][i];
		return anc[u][0];
	}

	bool isKey[N];
	pint cnt[N];

	pint dp(int u, int pa) {
		for (auto v: va[u]) {
			auto res = dp(v, u);
			cnt[u].fi += res.fi;
			cnt[u].se += res.se;
		}
		ans += 1LL * (sam::len[u] - sam::len[pa]) * cnt[u].fi * cnt[u].se;
		auto ret = cnt[u];
		cnt[u] = {0, 0};
		return ret;
	}

	void buildVTree(vector<int> &vec) {
		for (auto o: vec) isKey[o] = 1;
		vec.push_back(1);

		auto cmp = [](int a, int b) {
			return dfnL[a] < dfnL[b];
		};
		sort(all(vec), cmp);

		int siz = vec.size();
		for (int i = 1; i < siz; i++)
			vec.push_back(getLCA(vec[i - 1], vec[i]));
		sort(all(vec), cmp);
		vec.erase(unique(all(vec)), vec.end());

		// 初始化 va
		for (auto o: vec) va[o].clear();

		// u 在 rt 的子树中
		auto isInTree = [](int rt, int u) {
			return dfnL[rt] <= dfnL[u] && dfnR[u] <= dfnR[rt];
		};

		static int stk[N];
		int top = 0;
		for (auto o: vec) {
			while (top && !isInTree(stk[top], o)) top--;
			if (top) va[stk[top]].push_back(o);
			stk[++top] = o;
		}

		auto ret = dp(1, 0);
		ans += 1LL * ret.fi * ret.se;

		for (auto o: vec) isKey[o] = 0;
	}
}; // namespace vtree

string s;
int len9[N], len0[N];

int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	cin >> s;
	s = " " + s;

	for (int i = n; i >= 1; i--) {
		len9[i] = s[i] == '9' ? len9[i + 1] + 1 : 0;
		len0[i] = s[i] == '0' ? len0[i + 1] + 1 : 0;
	}

	for (int i = 1; i <= n; i++)
		sam::insert(s[i] - '0', i);

	sam::build_tree(vtree::a);
	sam::posToEnd[0] = 1;
	vtree::dfs(1, 0);

	for (int p = 0; p < 9; p++) {
		static vector<int> pos9[N], pos0[N];
		for (int len = 0; len <= n; len++) {
			pos9[len].clear();
			pos0[len].clear();
		}

		for (int i = 1; i <= n; i++)
			if (s[i] - '0' == p) {
				for (int j = 0; j <= len9[i + 1]; j++)
					pos9[j].push_back(sam::posToEnd[i - 1]);
				i += len9[i + 1];
			}

		for (int i = 1; i <= n; i++)
			if (s[i] - '0' == p + 1) {
				for (int j = 0; j <= len0[i + 1]; j++)
					pos0[j].push_back(sam::posToEnd[i - 1]);
				i += len0[i + 1];
			}

		for (int len = 0; len <= n; len++) {
			if (!pos9[len].empty() && !pos0[len].empty()) {
				vector<int> vec;
				for (auto o: pos9[len]) {
					vec.push_back(o);
					vtree::cnt[o].fi++;
				}
				for (auto o: pos0[len]) {
					vec.push_back(o);
					vtree::cnt[o].se++;
				}
				vtree::buildVTree(vec);
			}
		}
	}

	cout << ans << endl;

	return 0;
}
