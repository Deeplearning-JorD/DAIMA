/*
 * @Author: JorD
 * @LastEditTime: 2023-04-04 00:26:56
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
using ull = unsigned long long;
void Solve(){
    ull n;
    cin >> n;
    auto dfs = [&](auto dfs, ull x, ull a, ull b, ull c) -> void{
        if(x == 0){
            cout << 1 << endl;
            return;
        }
        if(x == 1){
            if(c >= 64) cout << 0 << endl;
            else cout << (1ull << c) << endl;
            return;
        }
        if(x & 1){
            dfs(dfs, x / 2, 2 * a + b, b, c + b);
        }else dfs(dfs, x / 2, a, a + 2 * b, c + a);
        return;
    };
    dfs(dfs, n, 1ull, 0ull, 0ull);
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}