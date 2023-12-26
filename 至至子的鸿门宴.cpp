/*
 * @Author: JorD
 * @LastEditTime: 2022-08-19 19:24:31
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
    int n;
    cin >> n;
    vector<ll> a(n+1);
    rep(i, 1, n) cin >> a[i];
    ll sum = 0;
    for(int i = n, j = 0;i >= 1;i--, j++){
        sum += (a[i] - 1 - a[i - 1]) * j;
    }
    if(sum & 1) cout << "ZZZ";
    else cout << "SSZ";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}