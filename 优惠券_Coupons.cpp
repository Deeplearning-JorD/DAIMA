/*
 * @Author: JorD
 * @Date: 2023-11-17 11:50:11
 * @LastEditTime: 2023-11-17 11:57:04
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
int n;
void Solve(){
    ll up = n, down = 1;
    for(int i = 2;i <= n;i ++){
        ll a = n * down;
        up *= i;
        down *= i;
        up += a;
        ll d = __gcd(down, up);
        down /= d;
        up /= d;
    }
    if(up % down == 0){
        cout << up << endl;
        return;
    }
    int len = log10(up / down) + 2;
    for(int i = 1;i <= len;i ++) cout << ' ';
    cout << up % down << endl;
    cout << up / down << ' ';
    for(int i = 1;i <= log10(down) + 1;i ++) cout << '-';
    cout << endl;
    for(int i = 1;i <= len;i ++) cout << ' ';
    cout << down << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    while(cin >> n)
    Solve();
    return 0;
}