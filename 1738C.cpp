/*
 * @Author: JorD
 * @LastEditTime: 2022-10-01 18:57:03
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
    vector<int> num(n + 1);
    int js = 0;
    rep(i, 1, n){
        ll x;   cin >> x;
        js += x&1;
    }
    if(js&1){
        if(js == 1){
            if((n - js)&1) cout << "Alice\n";
            else cout << "Bob\n";
        }else if((js/2)&1)cout << "Alice\n";
        else if((n - js)&1) cout << "Alice\n";
        else cout << "Bob\n";
        return;
    }else{
        if((js/2)&1) cout << "Bob\n";
        else cout << "Alice\n";
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