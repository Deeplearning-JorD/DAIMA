#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
const int N = 2e5 + 10;
vector<vector<int>> son;
int siz[N];
void dfs(int now){
    siz[now] = 1;
    for(auto x:son[now]){
        dfs(x);
        siz[now] += siz[x];
    }
}
int res(int now, int k){
    int mx = 0, tot = 0;
    for(auto x:son[now]){
        tot += siz[x];
        if(siz[x] > siz[mx]) mx = x;
    }
    if(k > 0) k --;
    if(tot - siz[mx] + 1 >= siz[mx] - k) return (tot - k) / 2;
    return (tot - siz[mx]) + res(mx, k + tot - siz[mx]);
}
void Solve(){
    int n; cin >> n;
    son.resize(n + 1);
    rep(i, 2, n){
        int fa; cin >> fa;
        son[fa].push_back(i);
    }
    dfs(1);
    cout << res(1, 0) << endl;
    son.clear();
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}