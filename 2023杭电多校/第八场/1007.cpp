/*
 * @Author: JorD
 * @LastEditTime: 2023-08-10 12:16:29
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
    int n, m;
    cin >> n >> m;
    vector<int> f(n + 1);
    rep(i, 1, n) f[i] = i;
    function<int(int)> find = [&](int i){
        if(i != f[i]) f[i] = find(f[i]);
        return f[i];
    };
    while(m --){
        int x, y; cin >> x >> y;
        f[find(x)] = find(y);
    }
    cin >> m;
    set<int> s;
    while(m --){
        int x; cin >> x;
        s.insert(find(x));
    }
    if(s.size() == 1) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}