/*
 * @Author: JorD
 * @Date: 2023-11-25 16:28:13
 * @LastEditTime: 2023-11-25 16:28:19
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
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int a = h1 * 60 + m1, b = h2 * 60 + m2;
    if(a == b) cout << 24 << ' ' << 0 << endl;
    else{
        if(a <= b) cout << (b - a) / 60 << ' ' << (b - a) % 60 << endl;
        else{
            int ls = 24 * 60;
            ls -= a - b;
            cout << ls / 60 << ' ' << ls % 60 << endl;
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