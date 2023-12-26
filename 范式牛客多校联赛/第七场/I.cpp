/*
 * @Author: JorD
 * @LastEditTime: 2023-08-09 02:02:55
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
const int mod = 998244353;
int tr[2][1 << 21];
int idx, cnt;
ll res;
int root[22];
string s; 
vector<string> son[401];
void add(int &p, int i){
    if(!p){
        p = ++ cnt;
        if(i == idx) res ++;
    }
    if(i >= idx) return;
    if(s[i] == '?'){
        add(tr[0][p], i + 1);
        add(tr[1][p], i + 1);
    }else if(s[i] == '1'){  
        add(tr[1][p], i + 1);
    }else add(tr[0][p], i + 1);
    return;
}
vector<string> ls; 
void dfs(int id, int i, int j){
    if(j == son[id].size()){
        if(i == 0) return;
        ll sum = 1;
        for(int k = 0;k < id;k ++){
            int a = 0, b = 0, c = 0;
            for(auto s:ls){
                if(s[k] == '0') a = 1;
                else if(s[k] == '1') b = 1;
                else c = 1;
            }
            if(a && b){
                sum = 0;
                break;
            }
            if(!a && !b) sum = (sum * 2) % mod;
        }
        if(i & 1) res = (res + sum) % mod;
        else res = (res - sum) % mod;
        return;
    }
    ls.push_back(son[id][j]);
    dfs(id, i + 1, j + 1);
    ls.pop_back();
    dfs(id, i, j + 1);
}
void Solve(){
    int n; cin >> n;
    while(n --){
        cin >> s;
        if(siz(s) <= 20){
            idx = s.size();
            add(root[idx], 0);
        }else{
            son[s.size()].push_back(s);
        }
    }
    for(int i = 1;i <= 400;i ++)if(!son[i].empty())dfs(i,0,0);
    cout << res % mod; 
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}