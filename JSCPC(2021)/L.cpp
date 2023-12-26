/*
 * @Author: JorD
 * @LastEditTime: 2022-12-07 01:39:24
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
const int MOD = 998244353;
void Solve(){
    int n;
    cin >> n;
    vector<vector<int>> son(n + 1);
    rep(i, 2, n){
        int p; cin >> p;
        son[p].push_back(i);
    }
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<ll> f(n + 1);
    function<void(int)> dfs = [&](int now){
        ll fac = f[now] = 1, cnt = 0, up = 0;
        if(a[now] == 0) cnt ++;
        unordered_map<int,int> q;
        for(auto x:son[now]){
            dfs(x);
            q[x] ++;
            if(!a[x]){
                fac *= ++ cnt;
                fac %= MOD;
            }
            f[now] *= f[x];
            f[now] %= MOD;
        }
        f[now] *= fac;
        f[now] %= MOD;
        if(a[now] && !q[a[now]]) up = a[now];
        for(auto x:son[now]){
            if(a[x] && !q[a[x]]){
                //遇到没出现过的只能给父节点。如果有多余的就是冲突了。
                if(up) f[now] = 0;
                else up = a[x];
            }
        }
        //每一层都可以换上去一个可能是不符合的节点
        a[now] = up;
    };
    dfs(1);
    if(a[1] <= 1) cout << f[1] << endl;
    else cout << 0 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}