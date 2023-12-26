/*
 * @Author: JorD
 * @LastEditTime: 2023-10-12 23:22:41
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
    map<int,int> st;
    rep(j, 1, n){
        int x; cin >> x;
        for(int i = 2;i <= x / i;i ++){
            if(x % i == 0){
                int cnt = 0;
                while(x % i == 0){
                    x /= i;
                    cnt ++;
                }  
                st[i] += cnt;
            }
        }
        if(x > 1) st[x] ++;
    }
    for(auto [x, y]:st){
        if(y % n){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}