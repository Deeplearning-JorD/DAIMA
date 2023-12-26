/*
 * @Author: JorD
 * @LastEditTime: 2023-05-05 21:49:45
 */
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
    vector<int> a(n + 1), depth(n + 1);
    rep(i, 1, n) cin >> a[i];
    depth[0] = -1;
    auto dfs = [&](auto self, int l, int r, int fa){
        if(l > r) return;
        int id = 0;
        rep(i, l, r){
            if(a[i] > a[id]){
                id = i;
            }
        }
        depth[id] = depth[fa] + 1;
        self(self, l, id - 1, id);
        self(self, id + 1, r, id);
    };
    dfs(dfs, 1, n, 0);
    rep(i, 1, n) cout << depth[i] << ' ';
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