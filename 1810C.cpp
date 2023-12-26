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
    ll n, c, d;
    cin >> n >> c >> d;
    set<ll> s;
    rep(i, 1, n){
        ll x; cin >> x;
        s.insert(x);
    }
    ll res = c * (n - siz(s)) + d * (*s.rbegin() - siz(s));
    ll idx = s.size(), w = c * (n - siz(s)), last = 0;
    for(auto i = s.rbegin();i != s.rend();i ++){
        res = min(res, w + last * c + d * ((*i) - (idx - last)));
        last ++;
    }
    res = min(c * n + d, res);
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}