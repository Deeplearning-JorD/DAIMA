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
int ne[N], st[N];
int idx = 0;
int instak[N];
int res = 1e9;
void dfs(int now){
    if(instak[now]){
        res = min(idx - instak[now], res);
        return;
    }
    if(st[now]) return;
    st[now] = 1;
    instak[now] = idx ++;
    dfs(ne[now]);
    instak[now] = 0;
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n) cin >> ne[i];
    rep(i, 1, n)if(!st[i]){
        idx = 1;
        dfs(i);
    } 
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}