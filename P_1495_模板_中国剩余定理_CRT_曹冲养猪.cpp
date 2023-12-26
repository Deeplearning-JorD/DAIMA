using namespace std;
#include <bits/stdc++.h>
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
// const int mod = 
ll exgcd(ll a, ll b, ll &x, ll &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return d;
}
ll inv(ll a, ll b){
    ll x, y;
    ll d = exgcd(a, b, x, y);
    return x;
}
void Solve(){
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    rep(i, 1, n) cin >> a[i] >> b[i];
    ll sum = 1, res = 0;
    rep(i, 1, n) sum *= a[i];
    rep(i, 1, n){
        ll c = sum / a[i];
        res = (res + b[i] * c * inv(c, a[i]) % sum) % sum;
    }
    cout << (res % sum + sum) % sum << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}