/*
 * @Author: JorD
 * @LastEditTime: 2023-01-01 21:19:25
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int mod = 998244353;
const int INV = 499122177;
void Solve(){
	int n;
	cin >> n;
	vector<vector<int>> son(n + 1);
	vector<int> a(n + 1), b(n + 1);
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> b[i];
	ll res = 1;
	rep(i, 1, n){
		int x = a[i], y = b[i];
		if(x == y){
			res *= n;
			res %= mod;
			res *= INV;
			res %= mod;
		}
		son[x].push_back(y);
		son[y].push_back(x);
	}
	vector<bool> st(n + 1);
	int js = 0, sum = 0;
	function<void(int)> dfs = [&](int now){
		if(st[now]) return;
		st[now] = true;
		js ++, sum += siz(son[now]);
		for(auto x:son[now]) dfs(x);
	};
	rep(i, 1, n)if(!st[i]){
		js = 0, sum = 0;
		dfs(i);
		if(sum != js * 2){
			cout << 0 << endl;
			return;
		}
		res *= 2;	
		res %= mod;
	}
	cout << res << endl;
	return;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin>>t; while(t --)
	Solve();
	return 0;
}