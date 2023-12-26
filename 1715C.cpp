/*
 * @Author: JorD
 * @LastEditTime: 2022-09-10 17:45:02
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 5);
    vector<ll> pre(n + 2), last(n + 2);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n){
        pre[i] = pre[i - 1];
        pre[i] += (a[i] != a[i - 1]);
    }
    per(i, n, 1){
        last[i] = last[i + 1] + pre[i];
    }
    int lose = -1;
    ll sum = 0;
    rep(i, 1, n){
        if(pre[i] != pre[i - 1]) lose ++;
        sum += last[i] - (n - i + 1) * lose;
    }
    while(m --){
        ll id, x;
        cin >> id >> x;
        if(a[id] == x){
            cout << sum << endl;
            continue;
        }
        if(x == a[id - 1]&&a[id - 1] != a[id]) sum -= (n - id + 1) * (id - 1);
        if(x != a[id - 1]&&a[id - 1] == a[id]) sum += (n - id + 1) * (id - 1);
        if(x == a[id + 1]&&a[id + 1] != a[id]) sum -= (n - id) * id;
        if(x != a[id + 1]&&a[id + 1] == a[id]) sum += (n - id) * id;
        cout << sum << endl;
        a[id] = x;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}