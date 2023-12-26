/*
 * @Author: JorD
 * @LastEditTime: 2022-08-14 14:59:21
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
ll m, k;
ll js(ll n){
    if(n<=1) return 0;
	ll res=0;
	ll last=n;
	ll p=1;
	ll now=last%10;
	last/=10;
	res+=last;
	while(last>0){
		now=last%10;
		last/=10;
		p*=10;
		if(now>0)
			res+=last*p;
		else if(now==0)
			res+=(last-1)*p+(n%p)+1;
	}
	return res;
}
ll get(ll x){
    if(x==0) return 1;
    ll res=0;
    while(x){
        res+=(x%10==0);
        x/=10;
    }
    return res;
}
bool check(ll mid){
    return js(m)-js(mid)+get(mid)>=k;
}
void Solve(){
    cin >> m >> k;
    ll l=0,r=m;
    int cnt=0;
    while(l<r){
        ll mid =l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    if(check(l)) cout<<l;
    else cout<<-1;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}