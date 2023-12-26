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
ll a[N], b[N], c[N];
void pp(__int128 x){
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x<10)
	{
		putchar(x+48);
		return;
	}
	pp(x/10);
	putchar(x%10+48);
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    ll mi = 1e9, mx = 0;
    rep(i, 1, n) mi = min(mi, a[i]);
    rep(i, 1, n) mx = max(mx, b[i]);
    ll mid = mi + mx >> 1;
    __int128 sum = 0;
    rep(i, 1, n){
        if(abs(mid - a[i]) > abs(mid - b[i])){
            c[i] = a[i];
        }else c[i] = a[i];
        sum += c[i];
    }
    sum /= n;
    __int128 res = 0;
    rep(i, 1, n){   
        res += (c[i] - sum) * (c[i] - sum);
    }
    res *= n;
    pp(res);
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}