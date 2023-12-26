#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
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
void Solve(){
    ll a, b, x, y, d, L; cin >> x >> y >> a >> b >> L;
    d = y - x;
    a = a - b;
    b = L;
    ll t = exgcd(a, b, x, y);
    if(d % t){
        cout << "Impossible";
        return;
    }
    a /= t; 
    b /= t;
    b = abs(b);
    x = (x % b + b) % b;
    x *= d / t;
    cout << (x % b + b) % b;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}