/*
 * @Author: JorD
 * @LastEditTime: 2022-12-19 08:13:22
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
int jiji = 0;
void Solve(){
    jiji ++;
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    sort(a.begin() + 1, a.end());
    ll l = 0, r = - n, res = 0;
    rep(i, 1, n){
        if(x >= a[i]){
            x ++;
            l ++, r ++;
            res ++;
        }else break;
        if(x == y){
            cout << i << endl;
            return;
        }
    }
    if(l + r <= 0){
        cout << -1 << endl;
        return;
    }
    while(x < y){
        if(l != n){
            ll L = 1, R = 1e12 / (l + r) + 1;
            while(L < R){
                ll mid = L + R >> 1;
                if(x + (l + r) * mid >= a[l + 1]||y - (x + (l + r) * (mid - 1) + r) <= l) R = min(R, mid);
                else L = mid + 1;
            }
            if((x + (R - 1) * (l + r) + r) + l >= y){
                res += y - (x + (R - 1) * (l + r) + r) - r + (R - 1) * n;
                break;
            }
            res += R * n;
            x += R * (l + r);
            for(int i = l + 1;i <= n;i ++){
                if(x == y) break;
                if(x >= a[i])
                    x ++, res ++, l ++, r++;
                else break; 
                if(x == y) break;
            }
        }else{
            res += (y - x) / n * n + (y - x) % n;
            break;
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