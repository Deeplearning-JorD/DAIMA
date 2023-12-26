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
const int N = 1e6 + 10;
int pr[N], tr[N], sa[N], num[N];
void Solve(){
	string s;
	cin >> s;
	int n = s.size(), m = 122;
	s = ' ' + s;
	for(int i = 1;i <= n;i ++) pr[i] = s[i], tr[i] = i;
	for(int i = 1;i <= n;i ++) num[pr[i]] ++;
	for(int i = 1;i <= m;i ++) num[i] += num[i - 1];
	for(int i = n;i >= 1;i --) sa[num[pr[i]] --] = tr[i];
	for(int w = 1, p = 0;w <= n;m = p, w <<= 1, p = 0){
		for(int i = n - w + 1;i <= n;i ++) tr[++ p] = i;
		for(int i = 1;i <= n;i ++) if(sa[i] > w) tr[++ p] = sa[i] - w;
		for(int i = 1;i <= m;i ++) num[i] = 0;
		for(int i = 1;i <= n;i ++) num[pr[i]] ++;
		for(int i = 1;i <= m;i ++) num[i] += num[i - 1];
		for(int i = n;i >= 1;i --) sa[num[pr[tr[i]]] --] = tr[i];
		swap(pr, tr);
		p = pr[sa[1]] = 1;
		for(int i = 2;i <= n;i ++)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		pr[sa[i]] = (tr[sa[i]] == tr[sa[i - 1]] && tr[sa[i] + w] == tr[sa[i - 1] + w]) ? p : ++ p;
		if(p == n) break;
	}
	rep(i, 1, n) cout << sa[i] << ' ';
	return;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	//int t; cin>>t; while(t --)
	Solve();
	return 0;
}