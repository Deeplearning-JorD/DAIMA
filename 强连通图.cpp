/*
 * @Author: JorD
 * @LastEditTime: 2023-01-28 19:55:07
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
vector<int> son[2000010];
int st[2001000];
void dfs(int now, int col){
    st[now] = col;
    for(auto x:son[now]){
        if(st[x] != col)
        dfs(x, col);
    }
}
int idx;
map<pair<int,int>,int> q;
void Solve(){
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    rep(i, 1, n) rep(j, 1, m) q[{i, j}]=++idx;
    rep(i, 1, n){
        rep(j, 2, m){
            if(s1[i - 1] == '<')
            son[q[{i, j}]].push_back(q[{i, j - 1}]);
            else son[q[{i, j - 1}]].push_back(q[{i, j}]);
         }
    }
    rep(i, 1, m){
        rep(j, 2, n){
            if(s2[i - 1] == '^') 
            son[q[{j, i}]].push_back(q[{j - 1, i}]);
            else son[q[{j - 1, i}]].push_back(q[{j, i}]);
        }
    }
    int res = 0, cnt = 0;
    rep(i, 1, n){
        rep(j, 1, m){
            cnt ++;
            dfs(q[{i, j}], cnt);
            rep(ii, 1, n)rep(jj, 1, m){
                int x = st[q[{ii,jj}]];
                if(x != cnt){
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}