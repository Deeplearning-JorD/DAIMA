/*
 * @Author: JorD
 * @LastEditTime: 2022-12-03 20:30:44
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
    ll n, nn;
    cin >> n;
    nn = n;
    map<ll, ll> q;
    ll sum = 0;
    for(ll i = 2;i <= n / i;i ++){
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
                q[i] ++;
                sum ++;
            }
        }
    }
    ll ss;
    if(n > 1) ss = n;
    if(n == nn){
        cout << n << endl;
        return;
    }
    for(ll i = 2;;i ++){
        ll now = i;
        for(auto &[x, y]:q){
            if(!y) continue;
            while(y && now % x == 0){
                now /= x;
                y --;
                sum --;
            }
        }
        if(!sum){
            cout << max(i, ss);
            break;
        }
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