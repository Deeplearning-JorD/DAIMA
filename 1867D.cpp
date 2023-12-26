/*
 * @Author: JorD
 * @LastEditTime: 2023-09-12 01:57:18
 * Ã§ÂÂnmÃ¦ÂÂ¶Ã¥Â¿ÂÃ¯Â¼ÂÃ¦ÂÂ¾Ã¤Â¸ÂªÃ§ÂÂ¯
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
    int n, k; cin >> n >> k;
    vector<vector<pair<int,int>>> son(n + 1);
    vector<int> st(n + 1), a(n + 1);
    int idx = 0, cnt = 0;
    bool res = true;
    rep(i, 1, n){
        int x; cin >> x;
        son[x].push_back({i, i});
        son[i].push_back({x, i});
        if(k == 1 && i != x) res = false;
    }
    function<void(int,int)> dfs = [&](int now, int e){
        if(st[now]){
            if(a[now] == -1) return;
            int len = idx - a[now] + 1;
            if(len == k) cnt = 1;
            else res = false;
            return;
        }
        st[now] = 1;
        a[now] = ++ idx;
        for(auto [x, y]:son[now])if(y != e){
            dfs(x, y);
        }
        idx --;
        a[now] = -1;
    };
    rep(i, 1, n)if(!st[i]){
        cnt = 0; idx = 0;
        dfs(i, 0);
        if(!cnt) res = false;
    }
    if(res) cout << "YES\n";
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