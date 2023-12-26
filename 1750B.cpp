/*
 * @Author: JorD
 * @LastEditTime: 2022-11-06 22:48:35
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
    string s;
    cin >> s;
    ll cnt1 = 0, cnt2 = 0;
    for(auto x:s){
        cnt1 += x == '1';
        cnt2 += x == '0';
    }
    if(cnt1 == 0){
        cout << cnt2 * cnt2 << endl;
        return;
    }
    if(cnt2 == 0){
        cout << cnt1 * cnt1 << endl;
        return;
    }
    ll res = cnt1 * cnt2;
    s = ' ' + s + ' ';
    cnt1 = cnt2 = 0;
    for(auto x:s){
        if(x == '1'){
            cnt1 ++;
            cnt2 = 0;
            res = max(res, cnt1 * cnt1);
        }else if(x == '0'){
            cnt2 ++;
            cnt1 = 0;
            res = max(res, cnt2 * cnt2);
        }
    }
    cout << res << endl;
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