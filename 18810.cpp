/*
 * @Author: JorD
 * @LastEditTime: 2023-10-12 22:46:02
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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int res = 1e9;
    for(int i = 0;i < n;i ++){
        int idx = 0, cnt = 0, j = i, sum = 1, js = 0;
        while(idx < m && b[idx] == a[j%n]){ 
            idx ++; j ++;   
        }
        if(idx == m){
            int x = n;
            while(x < j){
                x *= 2;
                cnt ++;
            }
            res = min(res, cnt);
        }
    }
    if(res == 1e9) res = -1;
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}