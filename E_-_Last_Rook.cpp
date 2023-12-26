/*
 * @Author: JorD
 * @LastEditTime: 2022-09-17 21:16:28
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
    int l = 1, r = n;
    int resl, resr;
    auto ask = [&](int a, int b, int c, int d, int e){
        cout << "?" << ' ' << a << ' ' << b << ' ' << c << ' ' << d << endl;
        int k;
        cin >> k;
        return k == e;
    };
    rep(i, 1, 10){
        int mid = l + r >> 1;
        if(ask(1, mid, 1, n, mid)){
            l = mid + 1;
        }else r = mid;
        if(l >= r) break;
    }
    resl = r;
    l = 1, r = n;
    rep(i, 1, 10){
        int mid = l + r >> 1;
        if(ask(1, n, 1, mid, mid)){
            l = mid + 1;
        }else r = mid;
        if(l >= r) break;
    }   
    resr = r;
    cout << "! ";
    cout << resl << ' ' << resr << endl;
    return;
}
int main(){
    Solve();
    return 0;
}