/*
 * @Author: JorD
 * @LastEditTime: 2023-10-15 15:33:55
 * how to Get
 */
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 2e5 + 10;
int f[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
void Solve(){
    int n, m; cin >> n >> m;
    int m1 = m;
    vector<int> siz(n << 1|1), w(n << 1|1, 2 * n);
    rep(i, 1, n << 1|1){
        f[i] = i;
        siz[i] = i <= n;
    }
    vector<vector<int>> son(n << 1|1);
    vector<vector<int>> fa(n << 1|1, vector<int> (20));
    int idx = n;
    rep(i, 1, m){
        int x, y; cin >> x >> y;
        x = find(x); y = find(y);
        if(x == y) continue;
        f[x] = f[y] = ++ idx;
        w[idx] = i;
        son[idx].push_back(x);
        son[idx].push_back(y);
        siz[idx] = siz[x] + siz[y];
        fa[x][0] = fa[y][0] = idx;
    }
    for(int j = 1;j <= 18;j ++)
    for(int i = 1;i <= idx;i ++)
        fa[i][j] = fa[fa[i][j - 1]][j - 1];
    auto check = [&](int x, int y, int mid){
        for(int i = 18;i >= 0;i --){
            if(w[fa[x][i]] <= mid) x = fa[x][i];
            if(w[fa[y][i]] <= mid) y = fa[y][i];
        }
        if(x == y) return siz[x];
        return siz[x] + siz[y];
    };
    cin >> m;
    while(m --){
        int x, y, z; cin >> x >> y >> z;    
        int l = 0, r = m1;
        while(l < r){
            int mid = l + r >> 1;
            if(check(x, y, mid) >= z) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}