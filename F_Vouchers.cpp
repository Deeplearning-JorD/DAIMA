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
const int N = 2e5 + 10;
int a[N], l[N], d[N], id[N], c[N];
void Solve(){
    int n, m; 
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> l[i];
    rep(i, 1, m) cin >> d[i];
    ll res = accumulate(a + 1, a + 1 + n, 0ll);
    rep(i, 1, m) id[i] = i;
    sort(a + 1, a + 1 + n);
    sort(id + 1, id + 1 + m, [&](int i, int j){
        return l[i] < l[j];
    });
    int r = 0;
    c[0] = n;
    priority_queue<int> q;
    for(int i = 1;i <= n;i ++){
        while(r <= m && a[i] >= l[id[r]]){
            q.push(d[id[r]]);
            r ++;
        }
        if(q.size()){
            res -= q.top();
            q.pop();
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}