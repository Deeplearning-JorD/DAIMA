/*
 * @Author: JorD
 * @LastEditTime: 2022-10-02 20:05:23
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
void Solve(){
    ll n, m;
    cin >> n >> m;
    map<ll, int> q;
    ll sum = 0;
    rep(i, 1, n){
        ll x;
        cin >> x;
        sum += x;
        q[x] ++;
    }
    ll k = sum / m;
    vector<ll> w;
    per(i, k, 0){
        if(w.size() >= 3) break; 
        w.push_back(i * m);
    }
    if(sum % m == 0){
        for(auto x:q){
        if(x.second == 0) continue;
        for(auto y:w){
            ll need = sum - x.first - y;
            if(need != x.first&&q[need]){
                cout << m << endl; 
                return;
            }
            if(need == x.first&&x.second > 1){
                cout << m << endl;
                return;
            }
        }
    }
    }
    for(auto x:q){
        if(x.second == 0) continue;
        for(auto y:w){
            ll need = sum - x.first - y;
            if(need != x.first&&q[need]){
                cout << (x.first + need) % m << endl;
                return;
            }
            if(need == x.first&&x.second > 1){
                cout << (x.first + need) % m << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)    
    Solve();
    return 0;
}