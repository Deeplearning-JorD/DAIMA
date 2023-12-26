/*
 * @Author: JorD
 * @Date: 2023-12-05 22:47:45
 * @LastEditTime: 2023-12-05 22:47:50
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
    string s; cin >> s;
    for(int i = 1;i <= 8;i ++)if(i != s[1] - '0'){
        cout << s[0] << i << endl;
    }
    for(auto i = 'a';i <= 'h';i ++)if(i != s[0]){
        cout << i << s[1] << endl;
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