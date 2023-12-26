/*
 * @Author: JorD
 * @LastEditTime: 2023-03-31 23:53:33
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
    int zhenikun;
    cin >> zhenikun;
    ll down = -1, up = -1, h = -1;
    while(zhenikun --){
        int op;
        cin >> op;
        if(op == 1){
            ll a, b, d;
            cin >> a >> b >> d;
            ll l = (d - 1) * (a - b) + b;
            if(d == 1) l = 0;
            ll r = (d - 1) * (a - b) + a;
            if(h == -1){
                down = l + 1, up = r;
                cout << 1 << ' ';
                h = 0;
            }else{
                if(l >= up || r < down){
                    cout << 0 << ' ';
                    continue;
                }
                l ++;
                down = max(down, l);
                up = min(up, r);
                cout << 1 << ' ';
            }
        }else{
            ll a, b;
            cin >> a >> b;
            if(down == -1 || h == -1){
                cout << -1 << ' ';
                continue;
            }
            ll l = 0, r = 1e18;
            while(l < r){
                ll mid = l + r + 1 >> 1;
                if((__int128)mid * (a - b) + (mid == 0?0:b) < (__int128)down) l = mid;
                else r = mid - 1;
            }
            if(l * (a - b) + (l == 0?0:b) + 1 <= down && l * (a - b) + a >= up) cout << l + 1 << ' ';
            else cout << -1 << ' ';
        }
    }
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}