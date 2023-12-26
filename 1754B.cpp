/*
 * @Author: JorD
 * @LastEditTime: 2022-10-23 16:01:07
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
    int l = n / 2, r = n;
    rep(i, 1, n){
        if(n & 1){
            if(i & 1){
                cout << r << ' ';
                r --;
            }else{
                cout << l << ' ';
                l --;
            }
        }else{
            if(i & 1){
                cout << l << ' ';
                l --;
            }else{
                cout << r << ' ';
                r --; 
            }
        }
    }
    cout << endl;
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