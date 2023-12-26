/*
 * @Author: JorD
 * @LastEditTime: 2022-09-24 19:16:20
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
const int N = 2e5 + 10;
int tr[N << 2];
int a[N];
void build(int l, int r, int p){
    if(l == r){
        tr[p] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
    tr[p] = min(tr[p << 1], tr[p << 1|1]);
}
int query(int l, int r, int cl, int cr, int p){
    if(cl > cr) return 2;
    if(cl <= l && r <= cr) return tr[p];
    int mid = l + r >> 1;
    int res = 1e9;
    if(mid >= cl)  res = query(l, mid, cl, cr, p << 1);
    if(mid < cr) res = min(res, query(mid + 1, r, cl, cr, p << 1|1));
    return res;
}
void Solve(){
    int n;
    cin >> n;
    vector<int> p;
    rep(i, 1, n){
        int x;
        cin >> x;
        a[i] = x;
        if(x & 1) p.push_back(i);
    }
    if(p.size() & 1){
        cout << "NO" << endl;
        return;
    }
    build(1, n, 1);
    int l = 0, r = 1;
    bool res = true;
    for(;r < p.size();l += 2, r += 2){
        if(query(1, n, p[l] + 1, p[r] - 1, 1) < 2) res = false;
    }
    if(res) cout << "YES" << endl;
    else cout << "NO" << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}