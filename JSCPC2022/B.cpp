/*
 * @Author: JorD
 * @LastEditTime: 2023-03-30 19:40:16
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
const int N = 2e4 + 10;
bool ck(int x){
    if(x <= 1) return false;
    for(int i = 2;i <= x / i;i ++){
        if(x % i == 0) return false;
    }
    return true;
}
vector<int> pr;
vector<int> son[N];
bool st[N];
int num[N];
int idx, ff, n;
void add(int x){
    for(int l = 1, r = x - 1;l < r;l ++, r --){
        if(l > n || r > n) continue;
        son[l].push_back(r);
        son[r].push_back(l);
        num[l] ++; num[r] ++;
    }
}
vector<int> res[N];
void dfs(int now, int top, int depth){
    if(depth > n){
        ff = 2;
        return;
    }
    st[now] = true; 
    res[idx].push_back(now);
    for(auto x:son[now])if(x <= n){
        if(!st[x]) dfs(x, top, depth + 1);
        if(x == top && depth >= 2) ff = 1;
        if(ff) return;
    }
}
void Solve(){
    cin >> n;
    int sum = 0;
    vector<int> id(n + 1);
    rep(i, 1, 2 * n){
        if(ck(i))add(i);
        if(i <= n) id[i] = i;
    }
    sort(id.begin() + 1, id.end(),[&](int a, int b){
        return num[a] < num[b];
    });
    for(int i = 1;i <= n;i ++)if(!st[id[i]]){
        idx ++;
        ff = 0;
        dfs(id[i], id[i], 0);
        if(ff != 1){
            cout << -1 << endl;
            return;
        }
    }
    cout << idx << endl;
    for(int i = 1;i <= idx;i ++){
        auto &u = res[i];
        cout << u.size() << ' ';
        for(int j = 0;j < u.size();j ++) cout << u[j] << " \n"[j == u.size() - 1];
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