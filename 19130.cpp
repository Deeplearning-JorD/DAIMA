/*
 * @Author: JorD
 * @Date: 2023-12-18 22:35:21
 * @LastEditTime: 2023-12-18 22:37:31
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
    string s;
    cin >> s;
    auto ff = [&](string s){
        int res = 0;
        for(auto x:s){
            res = res * 10 + x - '0';
        }
        return res;
    };
    for(int i = 1;i < s.size();i ++){
        string a = s.substr(0, i), b = s.substr(i);
        if(ff(a) < ff(b) && a[0] != '0' && b[0] != '0'){
            cout << a << ' ' << b << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}