/*
 * @Author: JorD
 * @LastEditTime: 2022-09-23 20:59:30
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = ' ' + s;
	vector<bool> vis(n + 1);
	int idx = 0;
	ll res = 0;
	rep(i, 1, n){
		if(s[i] == '1') continue;
		for(int j = i; j <= n; j += i){
			if(vis[j]) continue;
			if(s[j] == '1') break;
			res += i;
			vis[j] = true;
		}
	}
	cout << res << endl;
	return;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin>>t;
	while(t --)
	Solve();
	return 0;
}