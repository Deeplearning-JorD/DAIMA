/*
 * @Author: JorD
 * @LastEditTime: 2022-11-04 22:54:28
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
void Solve(){
    int n;
    cin >> n;
    cout << (n + 1) / 2 << endl;
    if(n & 1){
        cout << 2 << ' ' << 3 * n << endl;
        n --;
    }
    int l = 1, r = n;
    while(l <= r){
        cout << 3 * l - 2 << ' ' << 3 * r << endl;
        l ++, r --;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}