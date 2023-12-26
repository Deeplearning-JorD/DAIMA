/*
 * @Author: JorD
 * @LastEditTime: 2023-01-16 13:47:53
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
    s = ' ' + s;
    int cnt = 0, cnt1 = 0;
    int l = 5, r = 5;
    rep(i, 1, 10){
        int last = 11 - i >> 1;
        if(i & 1){
            if(s[i] == '1')
                cnt ++;
            l --;
        }else{
            if(s[i] == '1')
                cnt1 ++;
            r --;
        }
        if(cnt - cnt1 > r){
            cout << i << endl;
            return;
        }
        if(cnt1 - cnt > l){
            cout << i << endl;
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