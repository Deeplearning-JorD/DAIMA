/*
 * @Author: JorD
 * @LastEditTime: 2023-01-30 18:13:18
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
ll lowbit(ll x){
    return x & -x;
}
ll idx = 0, now;
ll lson(ll x){
    return x - (lowbit(x) >> 1);
}
ll rson(ll x){
    return x + (lowbit(x) >> 1);
}
ll get(ll x){
    ll d = 0;
    while((x >> d & 1) == 0){
        d ++;
    }
    return d;
}
ll N;
void dfs1(ll x){
    if(x > N) return;
    if(lowbit(x) == 1){
        idx ++;
        if(x == now){
            now = -1;
            return;
        }return;
    }
    if(lowbit(x)){
        idx ++;
        if(x == now){
            now = -1;
            return;
        }       
        if(now < x){
            dfs1(lson(x));
            if(now < 0) return;
        }
        idx += (1ll << get(x)) - 1;
        dfs1(rson(x));
    }
}
void dfs2(ll x){
    if(x > N) return;
    
    if(lowbit(x) == 1){
        idx ++;
        if(x == now){
            now = -1;
            return;
        }return;
    }
    if(lowbit(x) != 1){
        if(now < x){
            dfs2(lson(x));
        }
        if(now < 0) return;
        idx ++;
        idx += (1ll << get(x)) - 1;
        if(x == now){now = -1;return;}
        dfs2(rson(x));if(now < 0) return;
    }
}
void dfs3(ll x){
    if(x > N) return;
    if(lowbit(x) == 1){
        idx ++;
        if(x == now){
            now = -1;
            return;
        }return;
    }
    if(lowbit(x) != 1){
        if(x == now){
            idx += (1ll << get(x)) - 1;
            idx += (1ll << get(x)) - 1;
            idx ++;
            now = -1;
            return;
        }
        if(now < x){
            dfs3(lson(x));
            if(now < 0) return;
        }
        idx += (1ll << get(x)) - 1;
        dfs3(rson(x));if(now < 0) return;
    }
}
void Solve(){
    ll k, q;
    cin >> k >> q;
    N = 1ll << k;
    while(q --){
        ll x; cin >> x;
        idx = 0, now = x;
        dfs1(1ll<<k);now = x;
        cout << idx << ' ';
        idx = 0, now = x;dfs2(1ll<<k);
        cout << idx << ' ';
        idx = 0, now = x;
        if(x == N) cout << N << endl;
        else{dfs3(N);cout << idx << endl;}
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