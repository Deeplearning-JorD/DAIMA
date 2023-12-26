/*
 * @Author: JorD
 * @Date: 2023-11-20 19:44:24
 * @LastEditTime: 2023-11-20 20:20:23
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
void Solve(){
    int n; cin >> n;
    vector<int> op(n + 1);
    int a = 0, b = 0;
    rep(i, 1, n) cin >> op[i];
    auto check = [&](int id){
        int cnt = 1, w = 1;
        for(int i = 1;i <= n;i ++){
            int now = op[i]; if(now == 0) now = (i <= id) ? 1:-1;
            if(now == 1){
                w ++;
                cnt ++;
            }else{
                if(cnt < 2) return false;
                cnt --;
            }
        }
        a = w, b = cnt;
        return true;
    };
    int l = 1, r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(!check(l)){
        cout << -1 << endl;
        return;
    }
    int d = __gcd(a, b);
    a /= d;
    b /= d;
    cout << a << ' ' << b << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}