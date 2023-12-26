/*
 * @Author: JorD
 * @LastEditTime: 2023-05-08 20:08:09
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
void Solve(){
    string s;
    cin >> s;
    int n = s.size();
    set<char> q;
    for(auto x:s)q.insert(x);
    if(q.size() == 1){
        cout << -1 << endl;
        return;
    }
    int l = 0, r = n - 1;
    bool st = false;
    while(l < r){
        if(s[l] != s[r]) st = true;
        l ++, r --; 
    }
    if(st) cout << n << endl;
    else cout << n - 1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}