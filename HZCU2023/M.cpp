/*
 * @Author: JorD
 * @LastEditTime: 2023-04-28 14:59:08
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
    int n, k;
    cin >> n >> k;
    if(n & 1){
        int l = -1e9, r = 1e9;
        for(int i = 2;i <= n;i += 2, l ++, r --)
            cout << l << ' ' << r << ' ';
        cout << k << endl;
        return;
    }
    int l = -5e8, r = k - l;
    cout << l << ' ' << r << ' ';
    n -= 2;
    r --;
    l = -r;
    while(n){
        cout << l << ' ' << r << ' ';
        l ++, r --;
        n -= 2;
    }
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}