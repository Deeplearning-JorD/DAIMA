/*
 * @Author: JorD
 * @LastEditTime: 2022-10-21 00:16:43
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const ll mod = 998244353;

ll query(ll n,ll x){
    vector<ll> a;
    for(ll i = 2;i <= x/i;i ++){
        if(x % i == 0){
            a.push_back(i);
            while(x%i == 0) x /= i;
        }
    }
    if(x > 1) a.push_back(x);
    ll sum = 0;
    for(int i = 1;i < (1 << siz(a));i ++){
        ll z = 1, num = 0;
        rep(j, 0, siz(a) - 1){
            if(i >> j & 1){
                z *= a[j];
                num ++;
            }
        }
        if(num & 1) sum += n / z;
        else sum -= n / z;
    }
    return n - sum;
}
void Solve(){
    ll n, m;
    cin >> n;
    
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;
    Solve();
    return 0;
}