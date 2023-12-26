#pragma GCC optimize(2)
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
ll exgcd(ll a, ll b, ll &x, ll &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, b % a, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return d;
}
void Solve(){
    ll a1, b1, a2, b2, L, R;
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
    ll A = a1, B = -a2, C = b2 - b1;
    //A * k1 + B * k2 = C
    // A * x + B * y = gcd(A, B);
    ll x, y;
    ll g = exgcd(A, B, x, y);
    if(C % g){
        cout << -1 << endl;
        return;
    }  
    // A * x * C / g + B * x * C / g = C
    // k1 = (x * C - a2 * n) / g;
    // k2 = (y * C - a1 * n) / g;
    ll f = 1;
    if(g < 0){
        g = -g;
        x = -x;
        y = -y;
        f = -1;
    }
    ll mi = -1e18, mx = 1e18;
    ll l = -1e9, r = 1e9;
    while(l < r){
        ll mid = l + r >> 1;
        if((L - b1) / a1 <= (x * C - a2 * mid) / g) r = mid;
        else l = mid + 1;
    }
    mi = max(mi, r);
    l = -1e9, r = 1e9;
    while(l < r){
        ll mid = l + r + 1 >> 1;
        if((R - b1) / a1 >= (x * C - a2 * mid) / g) l = mid;
        else r = mid - 1;
    }
    // mx = min(mx, r);
    // l = -1e9, r = 1e9;
    // while(l < r){
    //     ll mid = l + r >> 1;
    //     if(L <= (y * C - f * a1 * mid) / g * a2 + b2) r = mid;
    //     else l = mid + 1;
    // }
    // mi = max(mi, r);
    // l = -1e9, r = 1e9;
    // while(l < r){
    //     ll mid = l + r + 1 >> 1;
    //     if(R >= (y * C - f * a1 * mid) / g * a2 + b2) l = mid;
    //     else r = mid - 1;
    // }
    // mx = min(mx, r);
    // l = -1e9, r = 1e9;
    // while(l < r){
    //     ll mid = l + r >> 1;
    //     if(0 <= (y * C - f * a1 * mid) / g) r = mid;
    //     else l = mid + 1;
    // }
    // mi = max(mi, r);
    // l = -1e9, r = 1e9;
    // while(l < r){
    //     ll mid = l + r >> 1;
    //     if(0 <= (x * C - f * a2 * mid) / g) r = mid;
    //     else l = mid + 1;
    // }
    // mi = max(mi, r);
    cout << mx - mi + 1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}