/*
 * @Author: JorD
 * @LastEditTime: 2023-03-22 00:11:16
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
const int N = 2e5 + 10;
int f[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
int n, mb, m;
int st[N];
void Solve(){
    cin >> n >> mb >> m;
    rep(i, 1, 2 * n) f[i] = i;
    while(m --){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            if(find(x) == find(y)){
                cout << "NO\n";
                return;
            }
            f[find(x)] = find(y + n);
            f[find(y)] = find(x + n);
        }else{
            if(find(x) == find(y + n)){
                cout << "NO\n";
                return;
            }
            f[find(x)] = find(y);
            f[find(x + n)] = find(y + n);
        }
    }
    vector<vector<int>> v(n), vv(n);
    int idx = 0;
    for(int i = 1;i <= n;i ++){
        int x = find(i), y = find(i + n);
        if(st[x] || st[y]){
            if(st[x]){
                v[st[x]].push_back(i);
            }else{
                vv[st[y]].push_back(i);
            }
        }else{
            st[x] = ++ idx;
            v[st[x]].push_back(i);
        }
    }
    for(int i = 1;i <= idx;i ++){
        if(v[i].size() > vv[i].size())
        swap(v[i], vv[i]);
    }
    vector<pair<int,int>> cnt(idx + 1);
    int sum = 0;
    for(int i = 1;i <= idx;i ++){
        sum += v[i].size();
        cnt[i] = {vv[i].size() - v[i].size(), i};
    }
    if(mb < sum){
        cout << "NO\n";
        return;
    }
    vector<pair<int,int>> js(n + 1);
    vector<vector<int>> dd(idx + 1);
    sort(cnt.begin() + 1, cnt.end());
    map<int,int> vis;
    int idx1 = 0;
    for(int i = 1;i <= idx;i ++){
        if(!vis[cnt[i].first]){
            vis[cnt[i].first] = ++ idx1;
        }
        dd[vis[cnt[i].first]].push_back(cnt[i].second);
    }
    vector<vector<int>> last(n + 1);
    vector<int> val(1);
    int idx2 = 0;
    for(int i = 1;i <= idx;i ++){
        int w = dd[i].size();
        for(int j = 0;(1 << j) <= w;j ++){
            int k = 0;
            ++ idx2;
            int tot = 0;
            while(k < 1 << j){
                int now = dd[i].back();
                last[idx2].push_back(now);    
                tot += vv[now].size() - v[now].size();
                dd[i].pop_back();
                k ++;
            }
            val.push_back(tot);
            w -= 1 << j;
        }
        if(w){
            ++ idx2;
            int tot = 0;
            while(w --){
                int now = dd[i].back();
                last[idx2].push_back(now);    
                tot += vv[now].size() - v[now].size();
                dd[i].pop_back();
            }
            val.push_back(tot);
        }
    }
    vector<int> dp(mb - sum + 1);
    vector<vector<int>> pre(idx2 + 1, vector<int> (mb - sum + 1));
    dp[0] = 1;
    for(int i = 1;i <= idx2;i ++){
        for(int j = mb - sum;j >= val[i];j --){
            if(dp[j - val[i]]){
                pre[i][j] = 1;
                dp[j] |= dp[j - val[i]];
            }
        }
    }
    if(!dp[mb - sum]){
        cout << "NO\n";
        return;
    }
    int up = pre[idx2][mb - sum], now = mb - sum;
    vector<int> res;
    for(int i = idx2;i >= 1;i --){
        if(up){
            now -= val[i];
            for(auto u:last[i]){
                for(auto x:vv[u])
                    res.push_back(x); 
            }
        }else{
            for(auto u:last[i]){
                for(auto x:v[u])
                    res.push_back(x);
            }
        }
        up = pre[i - 1][now];
    }
    cout << "YES\n";
    sort(res.begin(), res.end());
    for(auto x:res) cout << x << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}