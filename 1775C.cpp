/*
 * @Author: JorD
 * @LastEditTime: 2023-01-12 02:29:49
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
    ll n, x, nn, nnn, xx;
    cin >> n >> x;
    nn = n;
    nnn = n;
    xx = x;
    if((n & x) < x){
        cout << -1 << endl;
        return;
    }
    if(x == n){
        cout << x << endl;
        return;
    }
    vector<int> idx1, idx2;
    int i = 0;
    while(n){
        if(n & 1) idx1.push_back(i);
        n >>= 1;
        i ++;
    }
    idx2.push_back(i);
    i = 0;
    while(x){
        if(x & 1) idx2.push_back(i);
        x >>= 1;
        i ++;
    }   
    sort(all(idx2));
    i = 0;
    for(auto x:idx1){
        if(x < *idx2.begin()){
            i = x + 1;
            nn -= 1ll << x;
        }   
    }
    nn += 1ll << i;
    if((nnn & nn) != xx) cout << -1 << endl;
    else cout << nn << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}