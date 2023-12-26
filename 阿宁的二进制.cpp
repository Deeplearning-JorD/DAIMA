/*
 * @Author: JorD
 * @LastEditTime: 2023-02-03 14:37:17
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
int ji(int x){
    int res = 0;
    while(x){
        x -= x & -x;
        res ++;
    }
    return res;
}
const int N = 2e6 + 10;
int res[N];
void Solve(){
    int n, T;
    cin >> n >> T;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    priority_queue<ll> q;
    rep(i, 1, n) q.push(a[i]);
    int idx = 1;
    while(1){
        auto t = q.top(); q.pop();
        q.push(ji(t));
        res[idx] = q.top();
        if(res[idx] == 1) break; 
        idx ++;
    }
    while(T --){
        int k; cin >> k;
        if(k >= idx){
            cout << 1 << endl;
            continue;
        }
        cout << res[k] << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --
    Solve();
    return 0;
}