/*
 * @Author: JorD
 * @LastEditTime: 2023-03-16 21:51:19
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
void Solve(){
    ll n;
    cin >> n;
    ll res = 0;
    set<ll> s;
    for(int now = 2;now <= 1000;now ++){
        bool st = true;
        ll x = n;
        while(x){
            if(x % now > 1){
                st = false;
                break;
            } 
            x /= now;
        }
        if(st){
            s.insert(now);
        }
    }
    auto f = [&](int m, ll p){
        __int128 now = 1;
        __int128 sum = 0;
        ll inf = 2e18;
        bool st = false;
        for(int i = 0;i < 7;i ++){
            if(now > n) st = true;
            if(m >> i & 1){
                if(st) return inf;
                sum += now;
                if(sum > (__int128)n) return inf;
            }
            now *= p;
        }
        return (ll)sum;
    };
    for(int i = 0;i < (1 << 7);i ++){
        ll l = 1001, r = n;
        while(l < r){
            ll mid = l + r + 1 >> 1;
            if(f(i, mid) <= n) l = mid;
            else r = mid - 1;
        }
        if(f(i, r) == n) s.insert(r);
    }
    
    cout << s.size() << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}