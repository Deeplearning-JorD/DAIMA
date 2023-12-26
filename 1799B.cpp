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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int mi = 1e9, mx = 0;
    rep(i, 1, n){
        mi = min(mi, a[i]);
        mx = max(mx, a[i]);
    }
    if(mi == mx){
        cout << 0 << endl;
        return;
    }
    if(mi == 1){
        cout << -1 << endl;
        return;
    }
    vector<pair<int,int>> res;
    set<pair<int,int>> s;
    rep(i, 1, n){
        s.insert({a[i], i});
    }
    int idx = 0;
    while((*s.begin()).first != 2 && (*s.begin()).first != (*s.rbegin()).first){
        pair<int,int> x = *s.begin(), y = *(prev(s.end()));
        res.push_back({y.second, x.second});
        y.first = (y.first + x.first - 1) / x.first;
        s.erase((prev(s.end())));
        s.insert(y);
    }
    if((*s.begin()).first == (*s.rbegin()).first){
        goto GG;
    }
    for(auto [x, y]:s){
        auto now = *s.begin();
        while(x != 2){
            res.push_back({y, now.second});
            x = (x + 1) / 2;
        }
    }
    GG:
    cout << res.size() << endl;
    for(auto [x, y]:res) cout << x << ' ' << y << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}