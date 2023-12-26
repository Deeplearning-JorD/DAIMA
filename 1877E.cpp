/*
 * @Author: JorD
 * @LastEditTime: 2023-10-10 20:55:37
 * 就是标成1的已经满足了有白色儿子情况，所以可以不管他直接入队列了
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
    vector<int> a(n + 1), fa(n + 1), d(n + 1), col(n + 1);
    vector<vector<int>> son(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        son[a[i]].push_back(i);
        d[a[i]] ++;
        fa[i] = a[i];
    }
    int idx = 0;
    vector<bool> st(n + 1);
    bool flag = true;
    queue<int> q;
    rep(i, 1, n)if(!d[i]){
        q.push(i);
        st[i] = 1;
    }
    while(q.size()){
        auto t = q.front(); q.pop();
        if(!col[t]){
            if(!st[fa[t]]){
                col[fa[t]] = 1;
                q.push(fa[t]);
                st[fa[t]] = 1;
            }else if(!col[fa[t]]){
                flag = false;
                break;
            }
        }
        if(-- d[fa[t]] == 0 && !st[fa[t]]){
            q.push(fa[t]);
            st[fa[t]] = 1;
        }
    }
    vector<int> v, vis(n + 1);
    function<void(int,int)> dfs = [&](int now, int fa){
        if(vis[now]){
            if(siz(v) % 2){
                flag = false;
                return;
            }
            for(int i = 0;i < v.size();i ++){
                if(i & 1) col[v[i]] = 1;
            }
            return;
        }        
        v.push_back(now);
        vis[now] = 1;
        for(auto x:son[now])if(!st[x]){
            dfs(x, now);
        }
        v.pop_back();
    };
    rep(i, 1, n)if(!st[i] && !vis[i]){
        dfs(i, 0);
    }
    if(!flag){
        cout << -1 << endl;
        return;
    }
    vector<int> res;
    set<int> F, b;
    rep(i, 1, n)if(!col[i])res.push_back(i);
    cout << res.size() << endl;
    for(auto x:res) cout << a[x] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}