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
void Solve(){
    ll n, L, R;
    cin >> n >> L >> R;
    ll res = 1e18, id = 1e18;
    auto get = [&](ll x){
        if(x < 1||x > 1e18||x < L||x > R) return 0ll;
        ll now = n / x;
        now += x - 1;
        if(now == res){
            id = min(id, x);
        }
        if(now < res){
            res = now;
            id = x;
        }
        return now;
    };
    double l = 1, r = 1e18;
    int cnt = 0;
    while(fabs(l - r) > 1e-8 && cnt < 200){
        cnt ++;
        double mid = (l + r) / 2;
        if(mid <= n / mid) l = mid;
        else r = mid;
    }
    ll up = floor(r), down = ceil(r);
    if(get(up) > get(down)) up = down;
    down = get(up);
    ll l1 = L, r1 = up;
    int idx = 0;
    while(l1 < r1 && idx < 200){
        idx ++;
        ll mid = l1 + r1 + 1 >> 1;
        if(get(mid) != down) l1 = mid + 1;
        else r1 = mid;
    }
    res = 1e18, id = 1e18;
    get(L);get(R);
    get(up);get(l1);get(r1);
    for(ll i = l1 - 10;i <= l1 + 10;i ++) get(i);
    cout << id << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}