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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<bool> st(n + 1);
    rep(i, 1, n){
        cin >> a[i];
    }
    ll now = 0;
    rep(i, 1, 30){
        int idx = 0;
        ll last = now;
        rep(j, 1, n){
            if(st[j]) continue;
            if((last|a[j]) > now){
                now = last|a[j];
                idx = j;
            }
        }
        if(!idx) break;
        st[idx] = true;
        cout << a[idx] << ' ';
    }
    rep(i, 1, n) if(!st[i]) cout << a[i] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}