#include <bits/stdc++.h>
using namespace std;
using db = double;
using ll = long long;
#define edl '\n'
#define str string
#define pll pair<ll, ll>
#define fir first
#define sec second
#define heap priority_queue
#define SPO(n) fixed << setprecision(n)
#define FOR(i, l, r) for (auto i = l; i <= (r); ++i)
#define ROF(i, r, l) for (auto i = r; i >= (l); --i)
#ifdef debugcmd
#define DBG(n) cout << "!!! " << #n << ": " << n << edl
#else
#define DBG(n) ;
#endif
// const db PI = acos(-1.0);
// const db EPS = 1.0e-9;
const long long LNF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MXN = 2e5 + 5;
ll a[MXN];
ll s[MXN];

void Solve(void)
{
	ll n, p, q, r;
	cin >> n >> p >> q >> r;
	FOR(i, 1, n)
	cin >> a[i];
	FOR(i, 1, n)
	s[i] = s[i - 1] + a[i];
	FOR(i, 1, n)
	{
		ll val1 = p + q + r;
		ll val2 = val1 + s[i - 1];
		ll aim1 = lower_bound(s + 1, s + n + 1, val2) - (s + 1);
		ll aim2;
		if (s[aim1] - s[i - 1] == val1)
		{
			aim1 = lower_bound(s + 1, s + n + 1, p + s[i - 1]) - (s + 1);
			if (s[aim1] - s[i - 1] == p)
			{
				aim1 = lower_bound(s + 1, s + n + 1, q + s[i - 1]) - (s + 1);
				if (s[aim1] - s[i - 1] == q)
				{
					aim2 = aim1 + 1;
					aim1 = lower_bound(s + 1, s + n + 1, r + s[i - 1]) - (s + 1);
					if (s[aim1] - s[aim2 - 1] == r)
					{
						cout << "Yes" << edl;
						return;
					}
				}
			}
		}
	}
	cout << "No" << edl;
	return;
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	// #ifdef cincoutcmd
	// freopen("cin.txt","r",stdin);
	// freopen("cout.txt","w",stdout);
	// #endif

	Solve();
	return 0;
}
