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
    int n; cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    sort(all(a));
    vector<pair<bool, bool>> pre(n + 1), last(n + 2);
    vector<pair<int,int>> js(n + 1);
    pre[0].second = 1;
    rep(i, 1, n){
        pre[i] = pre[i - 1];
        if(a[i] & 1) pre[i].first |= 1;
        else pre[i].second |= 1;
    } 
    int cnt1 = 0, cnt2 = 0;
    rep(i, 1, n){
        if(a[i] & 1){
            if(pre[i - 1].first) js[i].second = 1;
            if(pre[i - 1].second) js[i].first = 1;
        }else{
            if(pre[i - 1].first) js[i].first = 1;
            if(pre[i - 1].second) js[i].second = 1;
        }
        cnt1 += js[i].first;
        cnt2 += js[i].second;
    }
    if(cnt1 == n || cnt2 == n) cout << "YES\n";
    else cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}