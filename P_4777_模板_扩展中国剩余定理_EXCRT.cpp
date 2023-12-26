/*
 * @Author: JorD
 * @LastEditTime: 2023-07-26 14:50:19
 */
#include <bits/stdc++.h>
using namespace std;
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
using ll = long long;
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
    int n;
    cin >> n;
    vector<long long> a(n + 1), b(n + 1);
    rep(i, 1, n){
        cin >> a[i] >> b[i];
        b[i] %= a[i];
    }
    ll B = b[1], A = a[1];
    for(int i = 2;i <= n;i ++){
        ll k1, k2, r1, r2;
        ll d = exgcd(a[i], A, r1, r2);
        if((B - b[i]) % d != 0){
            cout << -1 << endl;
            return;
        }
        ll c = A / d;
        A = A / d * a[i];
        r1 = ((r1 * ((B - b[i]) / d)) % c + c) % c;
        B = b[i] + r1 * a[i] % A;
        B = (B % A + A) % A;
    }
    cout << (long long)(B % A);
    return;
}
int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}