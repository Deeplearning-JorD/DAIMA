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
int tr[N << 2], tag[N << 2];
void build(int l, int r, int p){
    tr[p] = 0;
    tag[p] = 0;
    if(l == r){
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1|1);
}
void pushdown(int p){
    if(!tag[p]) return;
    tr[p << 1] += tag[p];
    tr[p << 1|1] += tag[p];
    tag[p << 1] += tag[p];
    tag[p << 1|1] += tag[p];
    tag[p] = 0;
    return;
}
void update(int cl, int cr, int l, int r, int p, int k){
    if(cl <= l && r <= cr){
        tr[p] += k;
        tag[p] += k;
        return;
    }
    int mid = l + r >> 1;
    pushdown(p);
    if(cl <= mid) update(cl, cr, l, mid, p << 1, k);
    if(cr > mid) update(cl, cr, mid + 1, r, p << 1|1, k);
    tr[p] = min(tr[p << 1], tr[p << 1|1]);
}
void modify(int pos, int l, int r, int p, int k){
    if(l == r){
        tr[p] += k;
        return;
    }
    int mid = l + r >> 1;
    if(pos <= mid) modify(pos, l, mid, p << 1, k);
    else modify(pos, mid + 1, r, p << 1|1, k);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
int query(int cl, int cr, int l, int r, int p){
    if(cl <= l && r <= cr){
        return tr[p];
    }
    int mid = l + r >> 1;
    // pushdown(p);
    int res = 0;
    if(cl <= mid) res += query(cl, cr, l, mid, p << 1);
    if(cr > mid) res += query(cl, cr, mid + 1, r, p << 1|1);
    return res;
}
void Solve(){
    int n, m;
    cin >> n >> m;
    build(1, n, 1);
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<bool> st(n + 1);
    int idx = 1;
    vector<int> id;
    int res = 0;
    rep(i, 1, n){
        while(idx <= min(i + m - 1, n)){
            // cout << i << ' ' << a[idx] << ' ' << idx << endl;
            q.push({a[idx], idx});
            st[idx] = 1;
            idx ++;
        }
        st[max(0, i - m + 1)] = 0;
        while(q.size()){
            auto [t, j] = q.top();
            if(st[j] == 0) q.pop();
            break;
        }
        // if(query(min(min(n, i + m - 1) - m + 1, i), min(n, i + m - 1), 1, n, 1) >= 2) continue;
        while(query(min(min(n, i + m - 1) - m + 1, i), min(n, i + m - 1), 1, n, 1) < 2){
            auto [x, mid] = q.top(); q.pop(); st[mid] = 0;
            modify(mid, 1, n, 1, 1);
            // update(max(1, mid - m + 1), min(n, mid + m - 1), 1, n, 1, 1);
            id.push_back(mid);
            // cout << mid << ' ' << i << endl;
            // cout << i << ' ' << x << endl;
            res += x;   
        }
    }
    sort(id.begin(), id.end(), [&](int i, int j){
        return a[i] > a[j];
    });
    for(auto i:id){
        int l = max(1, i - m + 1), r = min(n, i + m - 1);
        bool ff = true;
        // cout << i << ":\n";
        for(int j = l;j <= i;j ++){
            // cout << query(j, min(n, j + m - 1), 1, n, 1) << ' ' << j << ' ' << endl; 
            if(query(j, min(n, j + m - 1), 1, n, 1) > 2) continue;
            ff = false;
        }
        if(ff){
            res -= a[i];
            // cout << i << ' ' << a[i] << endl;
            // update(l, r, 1, n, 1, -1);
            modify(i, 1, n, 1, -1);
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}