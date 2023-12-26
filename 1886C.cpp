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
void Solve(){
    string s; cin >> s;
    ll n = s.size();
    ll x; cin >> x;
    s = ' ' + s;
    ll pos = 0, p = 0;
    ll sum = 0, cnt = n;
    rep(i, 1, n + 1){
        sum += cnt;
        if(x <= sum){
            p = x - sum + cnt;
            break;
        }
        pos ++; cnt --;
    }
    set<ll> id, mx;
    rep(i, 1, n) id.insert(i);
    rep(i, 2, n){
        if(s[i - 1] > s[i]) mx.insert(i - 1);
    }
    while(pos --){
        mx.insert(*id.rbegin());
        ll now = *mx.begin();
        auto c = id.lower_bound(now);
        if(c != id.begin() && c != prev(id.end())){
            auto d = prev(c), e = next(c);
            if(s[*d] > s[*e]) mx.insert(*d);
        }
        mx.erase(now);
        id.erase(now);
    }
    for(auto x:id){
        p --;
        if(p == 0) cout << s[x];
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}