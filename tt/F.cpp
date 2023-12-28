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
const int N = 1e5 + 10;
pair<int,int> a[N];
int f[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
vector<int> son[N];
void Solve(){   
    int n, m; cin >> n >> m;
    rep(i, 1, n) f[i] = i;
    rep(i, 1, n) cin >> a[i].first >> a[i].second;
    rep(i, 1, m){
        int x, y; cin >> x >> y;
        f[find(x)] = find(y);
    }
    rep(i, 1, n) son[find(i)].push_back(i);
    int res = 1e9;
    rep(i, 1, n)if(son[i].size()){
        int z = 1e9, y = 0, up = 0, down = 1e9;
        for(auto x:son[i]){
            int l = a[x].first, r = a[x].second ;
            z = min(z, l);
            y = max(y, l);
            up = max(r, up);
            down = min(down, r);
        }
        // cout << z << ' ' << y << ' ' << down << ' ' << up << ' ' << siz(son[i]) << endl;
        res = min(res, 2 * (y - z) + 2 * (up - down));
    }
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