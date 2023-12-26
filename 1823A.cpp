/*
 * @Author: JorD
 * @LastEditTime: 2023-04-27 22:40:24
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
int g(int x){
    return (x - 1) * x / 2;
}
void Solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 1;i <= n;i ++){
        if(g(i) + g(n - i) == k){
            cout << "YES\n";
            rep(j, 1, i) cout << "1 ";
            rep(j, 1, n - i) cout << "-1 ";
            cout << endl;
            return;
        }
    }
    cout << "NO\n";
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}