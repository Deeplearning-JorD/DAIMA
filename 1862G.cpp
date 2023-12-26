/*
 * @Author: JorD
 * @LastEditTime: 2023-10-12 12:50:20
 * 你妈，n=1要特判
 * 维护相邻数的差
 * how to Get
 */
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
    int n; cin >> n;
    vector<int> a(n + 1);
    multiset<int> s, e;
    rep(i, 1, n){
        cin >> a[i];
        s.insert(a[i]);
    }
    int last = -1;
    for(auto x:s){
        if(last != -1)
        e.insert(x - last);
        last = x;
    }
    int m; cin >> m;
    while(m --){
        int i, x; cin >> i >> x;
        if(n == 1){
            cout << x << ' ';
            continue;
        }
        auto p = s.lower_bound(a[i]);
        if(p != s.begin()){
            auto c = prev(p);
            e.erase(e.find(*p - *c));
            auto d = next(p);
            if(d != s.end())
            e.insert(*d - *c);
        }
        if(p != prev(s.end())){
            auto c = next(p);
            e.erase(e.find(*c - *p));
        }
        s.erase(s.find(a[i]));
        s.insert(x);
        p = s.lower_bound(x);
        if(next(p) != s.end() && p != s.begin()){
            e.erase(e.find(*next(p) - *prev(p)));
        }
        if(next(p) != s.end()){
            e.insert(*next(p) - x);
        }
        if(p != s.begin()){
            e.insert(x - *prev(p));
        }
        a[i] = x;
        int res = *s.rbegin() + *e.rbegin();
        cout << res << ' ';
    }
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}