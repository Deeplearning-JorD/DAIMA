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
    string s; cin >> s;
    int a = 0, b = 0;
    for(auto x:s)if(x == '0') a ++;
    else b ++;
    string c = s;
    for(auto &x:c) x ^= 1;
    int res = 0;
    int n = s.size();
    for(auto x:c){
        if(x == '0') a --;
        else b --;
        if(a < 0 || b < 0) break;
        n --;
    }
    cout << n << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}