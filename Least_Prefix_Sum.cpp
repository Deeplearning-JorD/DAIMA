/*
 * @Author: JorD
 * @LastEditTime: 2023-01-04 00:58:58
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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    ll sum = 0;
    int res = 0;
    priority_queue<int,vector<int>,greater<int>> qq;
    rep(i, 1, n){
        cin >> a[i];
        if(i > m){
            qq.push(a[i]);
            sum += a[i];
            if(sum < 0){
                res ++;
                auto t = qq.top(); qq.pop();
                sum -= t * 2;
            }
        }
    }
    if(m == 1){
        cout << res << endl;
        return;
    }
    sum = 0;
    if(a[m] > 0){res ++;a[m]*=-1;}
    rep(i, 1, m) sum += a[i];
    ll now = 0;
    vector<int> v;
    priority_queue<int> q;
    vector<ll> pre(n + 1);
    map<int,int> st;
    rep(i, 1, m - 1){
        pre[i] = pre[i - 1] + a[i];
    }
    int idx = 0;
    per(i, m - 1, 1){
        while(pre[i] < sum){
            int t;
            t = q.top(); q.pop();
            sum -= 2 * t;
            res ++;
        }q.push(a[i]);
    }
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