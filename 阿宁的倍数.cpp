/*
 * @Author: JorD
 * @LastEditTime: 2023-02-03 15:54:02
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
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<vector<int>> q(2e5 + 10);
    for(int j = 1;j <= n;j ++){
        int x = a[j];
        for(int i = 1;i <= x / i;i ++){
            if(x % i == 0){
                q[i].push_back(j);
                if(x / i != i) q[x / i].push_back(j);
            }
        }
    }
    while(Q --){
        int op, x; cin >> op >> x;
        if(op == 1){
            n ++;
            for(int i = 1;i <= x / i;i ++){
                if(x % i == 0){
                    q[i].push_back(n);
                    if(x / i != i) q[x / i].push_back(n);
                }
            }
            a.push_back(x);
        }else{
            int i = a[x];
            auto p = upper_bound(q[i].begin(), q[i].end(), x) - q[i].begin();
            cout << siz(q[i]) - p  << endl;
        }
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