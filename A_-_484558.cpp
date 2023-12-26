/*
 * @Author: JorD
 * @LastEditTime: 2022-10-01 20:03:34
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
string q = "0123456789ABCDEF";
void Solve(){
    int x;
    cin >> x;
    vector<int> s;
    while(x){
        s.push_back(x % 16);
        x /= 16;
    }
    reverse(s.begin(), s.end());
    rep(i, 1, 2 - siz(s)) cout << "0";
    for(auto x:s) cout << q[x];
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}