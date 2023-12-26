/*
 * @Author: JorD
 * @LastEditTime: 2023-05-24 21:15:19
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
int st[100][100];
void Solve(){
    // st[0][0] = 1;
    // for(int i = 0;i < 100;i ++){
    //     for(int j = 0;j < 100;j ++){
    //         if(st[i][j]) continue;
    //         st[i][j] = 1;
    //         int x = 1;
    //         for(int k = 0;k < 4;k ++, x *= 2){
    //             if(i - x >= 0 && st[i - x][j] == 1) st[i][j] = 2;
    //             if(j - x >= 0 && st[i][j - x] == 1) st[i][j] = 2;
    //         }
    //     }
    // }
    // rep(i, 0, 99){
    //     rep(j, 0, 99) cout << st[i][j]-1;
    //     cout << endl;
    // }
    ll n, p;
    cin >> n >> p;
    if(p & 1){
        ll cnt = 0;
        rep(i, 1, n){
            ll x; cin >> x;
            cnt += x & 1;
        }
        if(cnt & 1) cout << "GOOD\n";
        else cout << "BAD\n";
    }else{
        p ++;
        ll now = 0;
        rep(i, 1, n){
            ll x; cin >> x;
            x %= p;
            now += (x & 1) || (x == p - 1);
        }
        if(now & 1) cout << "GOOD\n";
        else cout << "BAD\n";
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