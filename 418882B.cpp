/*
 * @Author: JorD
 * @LastEditTime: 2023-01-02 19:14:45
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
    int a, b, k;
    cin >> a >> b >> k;
    if(a == b){
        cout << "1.";
        rep(i, 1, k) cout << 0;
    }else{
        cout << "0.";
        rep(i, 1, k - 1){
            a *= 10;
            if(a >= b){
                cout << a / b;
                a %= b;
            }else{
                cout << 0;
            }
        }
        int c = 0;
        a *= 10;
        if(a >= b){
            c = a / b;
            a %= b;
        }
        a *= 10;
        if(a >= b){
            a /= b;
            if(a >= 5) c ++;
        }
        cout << c;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}