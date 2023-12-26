/*
 * @Author: JorD
 * @LastEditTime: 2023-05-23 21:18:53
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
typedef pair<int,int> pii;
const int N = 5e5 + 10;
int a[N], b[N];
void Solve(){
    int n, k;
    cin >> n >> k;
    set<int> s;
    rep(i, 1, n){
        cin >> a[i];
        s.insert(a[i]);
    }
    if(s.size() < n){
        cout << 0 << endl;
        return;
    }
    sort(a + 1, a + 1 + n);
    rep(i, 2, n) b[i] = a[i] - a[i - 1];
    b[1] = 1e9;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    rep(i, 2, k - 1){
        q.push({b[i], i});
    }
    ll res = 2e18;
    for(int i = k;i <= n;i ++){
        q.push({b[i], i});
        while(q.size()){
            auto [w, id] = q.top();
            if(id <= i - k + 1){
                q.pop();
            }else{
                res = min(res, 1ll * w * (a[i] - a[i - k + 1]));
                break;
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