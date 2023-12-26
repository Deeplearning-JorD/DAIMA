/*
 * @Author: JorD
 * @LastEditTime: 2023-04-26 00:49:24
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
ll g(ll x){
    return x * (x - 1) * (x - 2);
}
void Solve(){
    int n;
    cin >> n;
    int mx = 0;
    int S = 1e6;
    map<int,int> q;
    rep(i, 1, n){
        int x; cin >> x;
        q[x] ++;
        mx = max(mx, x);
    }
    ll res = 0 ;
    for(auto [x, y]:q){
        res += g(y);
        if(x >= S){
            for(ll i = 2;i * x <= mx;i ++){
                if(x % i == 0 && q.count(x / i) && q.count(x * i)){
                    res += 1ll * y * q[x / i] * q[x * i];
                }
            }
        }else{
            vector<int> v;
            for(int i = 1;i <= x / i;i ++){
                if(x % i == 0){
                    v.push_back(i);
                    if(i != x / i) v.push_back(x / i);
                }
            }
            sort(v.begin(), v.end());
            for(auto now:v){
                if(now == 1) continue;
                if(1ll * now * x > mx) break;
                if(q.count(x / now) && q.count(x * now)){
                    res += 1ll * y * q[x / now] * q[x * now];
                }
            }
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}