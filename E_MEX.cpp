/*
 * @Author: JorD
 * @LastEditTime: 2023-07-05 17:30:10
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 2e5 + 10;
int pre[N][3], last[N][3];
int a[N];
void Solve(){
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    string s; cin >> s;
    s = ' ' + s;
    per(i, n, 1){
        rep(j, 0, 2) last[i][j] = last[i + 1][j];
        if(s[i] == 'X') last[i][a[i]] ++;
    }
    rep(i, 1, n){
        rep(j, 0, 2) pre[i][j] = pre[i - 1][j];
        if(s[i] == 'M') pre[i][a[i]] ++;
    }
    set<int> q;
    ll res = 0;
    rep(i, 1, n)if(s[i] == 'E'){
        rep(j, 0, 2){
            rep(k, 0, 2){
                rep(i, 0, 3) q.insert(i);
                q.erase(a[i]);
                q.erase(j);
                q.erase(k);
                ll sum = 1ll  * pre[i][j] * last[i][k];
                res += sum * (*q.begin());
            }
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}