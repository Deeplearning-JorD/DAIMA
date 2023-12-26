/*
 * @Author: JorD
 * @Date: 2023-11-25 23:34:30
 * @LastEditTime: 2023-11-27 14:15:29
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
    int n, m;  cin >> n >> m;
    set<int> s;
    vector<int> a(n + 1);
    rep(i, 1, n){
        cin >> a[i];
        if(a[i] == 1)
        s.insert(i);
    }
    while(m --){
        int op, i, x; cin >> op;
        if(op == 1){
            cin >> x;
            if((2 * n - siz(s)) < x){
                cout << "NO\n";
                continue;
            }
            if((2 * n - siz(s)) % 2 == x % 2){
                cout << "YES\n";
                continue;
            }
            if(s.empty()){
                if(x % 2 == 0) cout << "YES\n";
                else cout << "NO\n";
            }else{
                auto l = *s.begin(), r = *s.rbegin();
                int cnt = s.size() - 1;
                int can1 = 2 * (r - 1) - cnt;
                int can2 = 2 * (n - l) - cnt;
                if((x <= can1 && (x - can1) % 2 == 0) || (x <= can2 && (x - can2) % 2 == 0)) cout << "YES\n";
                else cout << "NO\n";
            }
        }else{
            cin >> i >> x;
            s.erase(i);
            if(x == 1) s.insert(i);
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}