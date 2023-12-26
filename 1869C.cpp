/*
 * @Author: JorD
 * @LastEditTime: 2023-09-10 23:28:05
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
    int n, m; cin >> n >> m;
    if(m == 1){
        cout << 0 << endl;
        rep(i, 1, n) cout << 0 << endl;
        return;
    }
    int can = 0;
    for(int i = 0;i < m;i ++){
        if(i > n) break;
        can = i;
    }
    vector<vector<int>> f(n + 1, vector<int> (m + 1));
    for(int i = 0;i < can;i ++){
        int k = can + 1;
        set<int> s;
        rep(j, 0, m - 1) s.insert(j);
        for(int j = i;j >= 0;j --){
            f[i + 1][k --] = j;
            s.erase(j);
        }
        for(;k >= 1;k --){
            auto p = *s.begin();
            if(k - 1 == p) p = *s.rbegin();
            f[i + 1][k] = p;
            s.erase(p);
        }
        k = can + 2;
        for(;k <= m;k ++){
            auto p = *s.begin();
            if(k - 1 == p) p = *s.rbegin();
            f[i + 1][k] = p;
            s.erase(p);
        }
    }
    for(int i = can + 1;i <= n;i ++){
        f[i] = f[i - 1];
    }
    cout << can + 1 << endl;
    rep(i, 1, n){
        rep(j, 1, m) cout << f[i][j] << ' ';
        cout << endl;
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