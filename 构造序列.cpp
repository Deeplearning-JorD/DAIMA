/*
 * @Author: JorD
 * @LastEditTime: 2022-12-17 19:29:19
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
const int N = 2e6 + 10;
int a[N];
void Solve(){
    int n, m;
    cin >> n >> m;
    if(n > m + 1 || 2 * n + 2 < m){
        cout << -1 << endl;
        return;
    }
    int idx = 1; 
    for(int j = 1;j <= n;j ++){
        a[idx] = 1;
        if(m){
            m --;
            a[idx + 1] = 1;
        }
        idx += 2; 
    }
    idx --;
    for(int i = 2;i <= idx;i += 2){
        if(m){
            m --;
            a[i] ++;
        }
    }
    while(m --){
        cout << 1;
    }
    idx = 1;
    while(a[idx]){
        rep(i, 1, a[idx]){
            if(idx & 1) cout << 0;
            else cout << 1;
        }
        idx ++;
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