/*
 * @Author: JorD
 * @LastEditTime: 2023-10-09 22:48:58
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
void Solve(){
    int n; cin >> n;
    if(n >= 5 && (n - 5) % 3 != 0 && n - 5 != 1 && n - 5 != 4){
        cout << "Yes\n";
        cout << 1 << ' ' << 4 << ' ' << n - 5 << endl;
        return;
    }
    if(n >= 3 && (n - 3) % 3 != 0 && n - 3 != 1 && n - 3 != 2){
        cout << "Yes\n";
        cout << 1 << ' ' << 2 << ' ' << n - 3 << endl;
        return;
    }
    if(n >= 7 && (n - 7) % 3 != 0 && n - 7 != 2 && n - 7 != 5){
        cout << "Yes\n";
        cout << 2 << ' ' << 5 << ' ' << n - 7 << endl;
        return;
    }
    cout << "No\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}