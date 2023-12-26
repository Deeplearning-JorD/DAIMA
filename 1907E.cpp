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
int ff;
int N;
ll p[100];
int g(int x){
    int res = 0;
    while(x){
        res += x % 10;
        x /= 10;
    }
    return res;
}
bool can(int i, int j, int k){
    return g(i) + g(j) + g(k) == g(i + j + k);
}
void Solve(){
    string s; cin >> s;
    ll res = 1;
    for(auto x:s){
        res *= p[x - '0'];
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    p[0] = 1;
    ll c = 2;
    for(int i = 1;i <= 65;i ++, c++){
        p[i] = p[i - 1] + c;
    }

    int t; cin>>t; while(t --)
    // N = 10;
    Solve();
    // for(int ff = 20;ff <= 30;ff += 1){
    //     N = ff;
    //     // cout <<  << ' ';
    //     Solve();
    // }
    // cout << endl;
    // for(int ff = 320;ff <= 330;ff += 1){
    //     N = ff;
    //     // cout <<  << ' ';
    //     Solve();
    // }
    // cout << endl;
    // // for(int ff = 1200;ff <= 1205;ff += 1){
    // //     N = ff;
    // //     // cout <<  << ' ';
    // //     Solve();
    // // }
    // cout << endl;
    return 0;
}