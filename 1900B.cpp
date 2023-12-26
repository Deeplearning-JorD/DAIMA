/*
 * @Author: JorD
 * @Date: 2023-11-26 22:48:41
 * @LastEditTime: 2023-11-26 23:07:41
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
    int a, b, c;
    cin >> a >> b >> c;
    auto chekc = [](int a, int b, int c) -> int{
        int mi = min(a, b);
        c += mi;
        a -= mi;
        b -= mi;
        int d = a + b;
        if(d % 2) return 0;
        return c >= 1;
    };
    cout << chekc(b, c, a) << ' ' << chekc(a, c, b) << ' ' << chekc(a, b, c) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}