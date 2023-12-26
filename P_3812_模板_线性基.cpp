/*
 * @Author: JorD
 * @Date: 2023-11-01 12:48:06
 * @LastEditTime: 2023-11-01 13:02:25
 * how to Get
 */
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
const int N = 110;
ll d[N], n;
void add(ll x){
    for(int i = 49;i >= 0;i --){
        if(x >> i & 1){
            if(!d[i]){
                d[i] = x;
                break;
            }else x ^= d[i];
        }
    }
}
void Solve(){
    cin >> n;
    rep(i, 1, n){
        ll x; cin >> x;
        add(x);
    }
    ll sum = 0;
    for(int i = 49;i >= 0;i --){
        if((sum ^ d[i]) > sum) sum ^= d[i];
    }
    cout << sum << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}