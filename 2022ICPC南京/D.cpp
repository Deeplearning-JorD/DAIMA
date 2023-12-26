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
int lowbit(int x){return x & -x;}
int tr[N], n;
void add(int i){
    for(;i <= n;i += lowbit(i)) tr[i] ++;
}
int query(int i){
    int res = 0;
    for(;i;i -= lowbit(i)) res += tr[i];
    return res;
}
void Solve(){
    ll k, m, c, d; cin >> n >> k >> m >> c >> d;
    vector<int> a(n + 1); rep(i, 1, n) cin >> a[i];
    auto clean = [&](){
        rep(i, 1, n) tr[i] = 0;
        return;
    };
    int id = 0;
    auto check = [&](ll up){
        int ban = 0;
        clean();
        vector<vector<int>> son(n + 1);
        for(int i = 1;i <= n;i ++){
            ll now = a[i];
            ban += now >= up;
            if(now >= up) continue;
            if(d == 0){
                if(now + c >= up)
                add(i);
                continue;
            }
            ll dd = (up - now - c + d - 1) / d; 
            int j = i - dd;
            if(dd < 0 || now + c >= up) j = i;
            if(j < 1) continue;
            if(j > n) continue;
            son[j].push_back(i);
        }
        if(d == 0){
            for(int i = n;i >= 1;i --){
                int j = min(1ll*n, i + m - 1);
                int now = query(j) + ban - query(i - 1);
                if(now >= k) return true;
            }
            return false;
        }
        for(int i = n;i >= 1;i --){
            for(auto j : son[i]){
                add(j);
            }
            int j = min(1ll*n, i + m - 1);
            int now = query(j) + ban - query(i - 1);
            if(now >= k) return true;
        }
        return false;
    };
    ll l = 0, r = 1e18;
    while(l < r){
        ll mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}