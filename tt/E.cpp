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
const int N = 1e6 + 10, M = 5e5 + 5;
string s;
// using ll = unsigned long long;
vector<int> son[N << 1];
ll k[N];
ll mp[N];
ll val;
void dfs(int now){
    if(s[now] == '(') val ++;
    else val --;
    k[now] += mp[val + M];
    mp[val + M] ++;
    for(auto x:son[now]){
        k[x] += k[now];
        dfs(x);
    }
    mp[val + M] --;
    if(s[now] == '(') val --;
    else val ++;
}
void Solve(){
    ll n; cin >> n;
    cin >> s;
    s = ' ' + s;
    rep(i, 2, n){
        int fa; cin >> fa;
        son[fa].push_back(i);
    }
    mp[0 + M] = 1;
    dfs(1);
    ll res = 0;
    rep(i, 1, n) cout << k[i] << ' '; //res ^= 1ll * i * k[i];
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