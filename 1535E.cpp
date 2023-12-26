/*
 * @Author: JorD
 * @LastEditTime: 2023-01-05 20:55:32
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 3e5 + 10;
int a[N], c[N];
int f[N][21];
void Solve(){
    int n;
    cin >> n >> a[0] >> c[0];
    rep(i, 1, n){
        int op; cin >> op;
        if(op == 1){
            cin >> f[i][0] >> a[i] >> c[i];
            rep(j, 1, 20) f[i][j] = f[f[i][j - 1]][j - 1];
        }else{
            int v, w;
            cin >> v >> w;
            ll need = 0, res = 0;
            while(w && a[v]){
                int u = v;
                for(int j = 20;j >= 0;j --){
                    if(a[f[u][j]]) u = f[u][j];
                }
                int use = min(a[u], w);
                w -= use;
                a[u] -= use;
                need += use;
                res += 1ll * c[u] * use;
            }
            cout << need << ' ' << res << endl;
        }
    }
    return;
}
int main(){
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}