/*
 * @Author: JorD
 * @LastEditTime: 2022-09-10 12:18:13
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> st(n + 1, vector<bool> (33));
    vector<vector<pair<ll,ll>>> f(n + 1);
    vector<ll> res(n + 1);
    rep(i, 1, m){
        ll x, y, z;
        cin >> x >> y >> z;
        if(x > y) swap(x, y);
        f[x].push_back({y, z});
        if(x == y){
            st[x][31] = true;
            res[x] = z;
        }
        rep(j, 0, 29){
            if(st[x][31]) st[x][j] = true;
            if((1 << j) & z) continue;
            st[x][j] = st[y][j] = true;
        }
    }
    rep(i, 1, n){
        for(auto x:f[i]){
            int ne = x.first, w = x.second;
            rep(j, 0, 29){
                int p = (res[ne]&(1<<j))|(res[i]&(1<<j));
                if(!((1 << j) & w)||p) continue;
                int fa = st[i][j], son = st[ne][j];
                if(!fa&&son){
                    st[i][j] = true;
                    res[i] += 1 << j;
                }
            }
        }
    }
    rep(i, 1, n){
        for(auto x:f[i]){
            int ne = x.first, w = x.second;
            rep(j, 0, 29){   
                if(((1 << j) & w)){
                    int p = (res[ne]&(1<<j))|(res[i]&(1<<j));
                    if(p) continue;
                    int fa = st[i][j], son = st[ne][j];
                    st[ne][j] = true;
                    res[ne] += 1 << j;
                }            
            }
        }
    }
    rep(i, 1, n)
        cout << res[i] << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}