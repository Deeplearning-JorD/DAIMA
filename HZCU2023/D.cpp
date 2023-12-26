/*
 * @Author: JorD
 * @LastEditTime: 2023-04-28 15:24:01
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
const int N = 1e6 + 10;
int f[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
void Solve(){
    int n;
    cin >> n;
    rep(i, 0, 2 * n) f[i] = i;
    int idx = 0;
    map<int,int> q;
    rep(i, 1, n){
        int x; cin >> x;
        q[x] = ++ idx;
        if(q.count(x - 9)){
            int l = i, r = q[x - 9];
            f[find(l)] = find(r + n);
            f[find(r)] = find(l + n);
        }
        if(q.count(x + 9)){
            int l = i, r = q[x + 9];
            f[find(l)] = find(r + n);
            f[find(r)] = find(l + n);
        }
    }
    int res = 0;
    vector<int> cnt(2 * n + 1);
    rep(i, 1, 2 * n){
        cnt[find(i)] ++;
    }
    rep(i, 1, 2 * n)if(cnt[i]){
        res += cnt[i] + 1 >> 1;
    }
    cout << res / 2 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}