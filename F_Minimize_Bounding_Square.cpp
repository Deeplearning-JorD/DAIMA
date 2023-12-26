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
    ll n, k; cin >> n >> k;
    vector<ll> x(n + 1), y(n + 1);
    rep(i, 1, n) cin >> x[i] >> y[i];
    auto check = [&](ll mid){
        map<ll,ll> s1;
        for(int i = 1;i <= n;i ++) s1[x[i]] ++;
        ll need = 0;
        while(1){
            if(s1.size() == 1) break;
            auto z = *s1.begin(), y = *(--s1.end());
            if(y.first - mid <= z.first || s1.size() == 1) break;
            ll can = y.first - z.first - mid;
            if(z.second > y.second){
                auto ne = *next(s1.begin());
                need += 1ll * min(can, abs(ne.first - z.first)) * z.second;
                if((ne.first - z.first) >= can) break;
                s1[ne.first] += z.second;
                s1.erase(z.first);
            }else{
                auto ne = *--(--s1.end());
                need += 1ll * min(can, abs(y.first - ne.first)) * y.second;
                if((y.first - ne.first) >= can) break;
                s1[(ne).first] += y.second;
                s1.erase(y.first);
            }
        }
        s1.clear();
        for(int i = 1;i <= n;i ++) s1[y[i]] ++;
        while(1){
            if(s1.size() == 1) break;
            auto z = *s1.begin(), y = *(--s1.end());
            if(y.first - mid <= z.first || s1.size() == 1) break;
            ll can = y.first - z.first - mid;
            if(z.second >= y.second){
                auto ne = *next(s1.begin());
                need += 1ll * (min(can, abs(ne.first - z.first))) * z.second;
                if(((ne).first - z.first) >= can) break;
                s1[(ne).first] += z.second;
                s1.erase(z.first);
            }else{
                auto ne = *--(--s1.end());
                need += 1ll * min(can, abs(y.first - (ne).first)) * y.second;
                if((y.first - (ne).first) >= can) break;
                s1[(ne).first] += y.second;
                s1.erase(y.first);
            }
        }
        return need <= k;
    };
    ll l = 0, r = 2e9;
    while(l < r){
        ll mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}