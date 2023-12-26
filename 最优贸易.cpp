/*
 * @Author: JorD
 * @LastEditTime: 2022-12-22 20:27:34
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<int, int>
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
    vector<int> c(n + 1);
    vector<vector<int>> son(n + 1);
    vector<vector<int>> zson(n + 1);
    rep(i, 1, n) cin >> c[i];
    for(int i = 1;i <= m;i ++){
        int x, y, z;
        cin >> x >> y >> z;
        if(z == 2){
            son[x].push_back(y);
            son[y].push_back(x);
            zson[x].push_back(y);
            zson[y].push_back(x);
        }else{
            son[x].push_back(y);
            zson[y].push_back(x);
        }
    }
    queue<pair<int,int>> q;
    vector<int> dist0(n + 1, 1e9), dist1(n + 1, 0);
    vector<bool> st(n + 1);
    int res = 0;
    q.push({c[1], 1});
    dist0[1] = c[1];
    st[1] = true;
    while(q.size()){
        auto [o, now] = q.front(); q.pop(); st[now] = false; 
        for(auto x:son[now]){
            int w = min(c[x], o);
            if(dist0[x] > w){
                dist0[x] = w;
                if(!st[x]){
                    st[x] = true;
                    q.push({dist0[x], x});
                }
            }
        }
    }    
    q.push({c[n], n});
    dist1[n] = c[n];
    st[n] = true;
    while(q.size()){
        auto [o, now] = q.front(); q.pop(); st[now] = false; 
        for(auto x:zson[now]){
            int w = max(c[x], o);
            if(dist1[x] < w){
                dist1[x] = w;
                if(!st[x]){
                    st[x] = true;
                    q.push({dist1[x], x});
                }
            }
        }
    }   
    rep(i, 1, n) 
    res = max(res, dist1[i] - dist0[i]);
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}