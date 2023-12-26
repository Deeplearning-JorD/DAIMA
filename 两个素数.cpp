/*
 * @Author: JorD
 * @LastEditTime: 2022-09-24 19:01:52
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
bool prime(int x){
    if(x <= 1) return false;
    for(int i = 2; i <= i/x; i ++ ){
        if(x%i == 0) return false;
    }
    return true;
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, 1000){
        if(n % i == 0&&prime(i)){
            if(prime(n/i)){
                cout << i << ' ' << n/i << endl;
                break;
            }
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;


    Solve();
    return 0;
}