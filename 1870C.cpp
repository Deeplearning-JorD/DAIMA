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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vector<int> pre(n + 1), suf(n + 2);
    rep(i, 1, n) pre[i] = max(pre[i - 1], a[i]);
    per(i, n, 1) suf[i] = max(suf[i + 1], a[i]);
    vector<vector<int>> d(k + 1, vector<int> (4, -1));
    vector<bool> st(k + 1);
    rep(i, 1, n){
        int l = 1, r = n;
        int x = a[i];
        st[x] = 1;
        while(l < r){
            int mid = l + r >> 1;
            if(pre[mid] >= x) r = mid;
            else l = mid + 1;
        }
        if(d[x][0] == -1) d[x][0] = r;
        else d[x][0] = min(d[x][0], r);
        if(d[x][3] == -1) d[x][3] = r;
        else d[x][3] = min(d[x][3], r);
        l = 1, r = n;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(suf[mid] >= x) l = mid;
            else r = mid - 1;
        }
        if(d[x][2] == -1) d[x][2] = r;
        else d[x][2] = max(d[x][2], r);
        if(d[x][1] == -1) d[x][1] = r;
        else d[x][1] = max(d[x][1], r);
    }
    rep(i, 1, k){
        if(!st[i]) cout << 0 << ' ';
        else cout << 2 + d[i][2] - d[i][0] + d[i][1] - d[i][3] << ' ';
    }
    cout << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}