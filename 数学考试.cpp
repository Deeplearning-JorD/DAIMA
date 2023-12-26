/*
 * @Author: JorD
 * @LastEditTime: 2022-10-02 20:28:41
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1), Q(n + 1), W(n + 1); 
    rep(i, 1, n) cin >> a[i] >> b[i] >> Q[i] >> W[i];
    ll res = 0;
    rep(u, 0, m){
        ll P1 = u, P2 = u, P3 = u;
        ll w1 = 0, w2 = 0, w3 = 0;
        rep(i, 1, n){
            if(P1 <= b[i]){
                w1 += P1 * a[i];
            } 
            if(P2 <= b[i]){
                w2 += P3 * a[i];
            }
            if(P3 <= b[i]){
                w3 += P3 * a[i];
            }
            
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}