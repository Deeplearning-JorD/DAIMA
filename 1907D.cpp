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
void Solve(){
    int n; cin >> n;
    vector<pair<int,int>> a(n + 1);
    rep(i, 1, n) cin >> a[i].first >> a[i].second;
    auto get = [&](int x, int y, int sx, int sy){
        int z = max(x, sx), r = min(y, sy);
        return pair<int,int>{z, r};
    };
    auto check = [&](int mid){
        int l = 0, r = 0;
        for(int i = 1;i <= n;i ++){
            auto [x, y] = a[i];
            l -= mid, r += mid;
            auto now = get(x, y, l, r);
            l = now.first, r = now.second;
            if(l > r) return false;
        }
        return true;
    };
    int l = 0, r = 1e9;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}