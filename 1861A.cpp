/*
 * @Author: JorD
 * @LastEditTime: 2023-08-31 22:40:18
 * how to Get
 */
#pragma GCC optimize(2)
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
bool prime(int x){
    if(x<2) return false;
    for(int i=2;i<=x/i;i++){
        if(x%i==0)
            return false;
    }
    return true;
}
void Solve(){
    string s; cin >> s;
    int now = s[0] - '0';
    for(int i = 1;i <= 9;i ++)if(i != now){
        if(prime(now * 10 + i)){
            cout << now * 10 + i << endl;
            return;
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