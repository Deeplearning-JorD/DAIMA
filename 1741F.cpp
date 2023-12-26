/*
 * @Author: JorD
 * @LastEditTime: 2022-10-13 20:20:55
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
const int N = 2e5 + 10, inf = 2e9 + 10;
int num;
struct Segtree{
    int ls, rs;
    int sum, tag;
}tr[N << 6];
inline void pushup(int p){ 
    tr[p].sum = tr[tr[p].ls].sum + tr[tr[p].rs].sum;
}
inline void pushdown(int p, int l, int r){
    if(!tr[p].ls) tr[p].ls = ++ num;
    if(!tr[p].rs) tr[p].rs = ++ num;
    auto &root = tr[p], &left = tr[tr[p].ls], &right = tr[tr[p].rs];
    if(root.tag){
        int mid = l + r >> 1;
        left.sum += (mid - l + 1) * root.tag;
        right.sum += (r - mid) * root.tag;
        left.tag += root.tag;
        right.tag += root.tag;
        root.tag = 0;
    }
    return;
}
inline void modify(int &p, int l, int r, int cl, int cr, int w){
    if(!p) p = ++ num;
    if(cl <= l && r <= cr){
        tr[p].sum += (r - l + 1) * w;
        tr[p].tag += w;
        return;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if(cl <= mid) modify(tr[p].ls, l, mid, cl, cr, w);
    if(mid < cr) modify(tr[p].rs, mid + 1, r, cl, cr, w);
    pushup(p);
}
inline int query(int p, int l, int r, int cl, int cr){
    if(!p) return 0;
    if(cl <= l && r <= cr){
        return tr[p].sum;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    int res = 0;
    if(cl <= mid) res += query(tr[p].ls, l, mid, cl, cr);
    if(mid < cr) res += query(tr[p].rs, mid + 1, r, cl, cr); 
    pushup(p);
    return res;
}
void Solve(){
    int n;
    cin >> n;
    vector<vector<tuple<int,int,int>>> son(n + 1);
    vector<int> res(n + 1, 2e9);
    vector<tuple<int,int,int>> a(n + 1);
    multiset<int> sL, sR;
    vector<int> idx;
    rep(i, 0, num) tr[i] = {0,0,0,0};
    num = 0; 
    int root = 0;
    rep(i, 1, n){
        int l, r, col;
        cin >> l >> r >> col;
        son[col].push_back({l, r, i});
        a[i] = {l, r, col};
        sL.insert(l);
        sR.insert(r);
        modify(root, 1, inf, l, r, 1);
    }  
    rep(i, 1, n){
        for(auto [l, r, j]:son[i]){
            sL.erase(sL.find(l));
            sR.erase(sR.find(r));
            modify(root, 1, inf, l, r, -1);
        }
        for(auto [l, r, j]:son[i]){
            if(query(root, 1, inf, l, r)){
                res[j] = 0;
                continue;
            }
            auto lR = sR.lower_bound(l);
            if(lR != sR.begin()){
                lR --;
                res[j] = min(l - *lR, res[j]);
            }
            auto rL = sL.lower_bound(r);
            if(rL != sL.end()){
                res[j] = min(res[j], *rL - r);
            }
        }
        for(auto [l, r, j]:son[i]){
            sL.insert(l);
            sR.insert(r);
            modify(root, 1, inf, l, r, 1);
        }
    }
    rep(i, 1, n) cout << res[i] << " \n"[i == n];
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