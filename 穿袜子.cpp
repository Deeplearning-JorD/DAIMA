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
struct node{
    int l, r, w;
};
map<int,int> st;
int idx;
void Solve(){
    int n;
    cin >> n;
    vector<node> a(n + 1); 
    ll res = 0;
    rep(i, 1, n){
        int p,m;
        char q;
        cin >> p >> q >> m;
        if(!st[p]) st[p] = ++ idx;
        int j = st[p];
        if(q == 'L'){
            a[j].l = m;
        }else if(q == 'R'){
            a[j].r = m;
        }else{
            a[j].w = m;
        }
        int now = a[j].l ? 1 : 0;
        now += a[j].r ? 1 : 0;
        now += a[j].w ? 1 : 0;
        if(now >= 2) res = 1;
    }
    ll now = 0;
    rep(i, 1, idx){
        auto [l, r, w] = a[i];
        if(l < r) swap(l, r);
        if(l){
            now += l;
        }else if(w) now ++;
    }
    if(res) cout << res + now << endl;
    else cout << -1 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}