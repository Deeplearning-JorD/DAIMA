/*
 * @Author: JorD
 * @LastEditTime: 2022-09-21 16:03:28
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
const int N = 2e5 + 10, M = 3e5 + 10;
int num[N],sum[M];
int tr[M << 2], mark[M << 2];
int n, t, res;
inline void pushdown(int p, int len){
    if(len <= 1){
        mark[p] = 0;
        return;
    }
    tr[p << 1] += mark[p] * (len - len / 2);
    mark[p << 1] += mark[p];
    tr[p << 1|1] += mark[p] * (len / 2);
    mark[p << 1|1] += mark[p];
    mark[p] = 0;
}
inline void build(int p, int l, int r){
    if(l == r){
        tr[p] = sum[l];
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1|1, mid + 1, r);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
inline void update(int l, int r, int cl, int cr, int p, ll x){
    if(cl <= l&&r <= cr){
        mark[p] += x;
        tr[p] += x * (r - l + 1);
        return;
    }
    pushdown(p, r - l + 1);
    int mid = l + r >> 1;
    if(mid >= cl) update(l, mid, cl, cr, p << 1, x);
    if(mid < cr) update(mid + 1, r, cl, cr, p << 1|1, x);
    tr[p] = tr[p << 1] + tr[p << 1|1];
}
inline ll query(int l, int r, int cl, int cr, int p){
    if(cl <= l&&r <= cr){
        return tr[p];
    }
    pushdown(p, r - l + 1);
    int mid = l + r >> 1;
    ll res = 0;
    if(mid >= cl) res += query(l, mid, cl, cr, p << 1);
    if(mid < cr) res += query(mid + 1, r, cl, cr, p << 1|1);
    return res; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> t;
    rep(i, 1, n){
        cin >> num[i];
        sum[num[i]] ++;
    }
    rep(i, 1, 3e5){
        if(sum[i]) res = i;
        sum[i + 1] += sum[i] >> 1;
        sum[i] &= 1;
    }
    build(1, 1, 3e5);
    while(t --){
        int x, y;
        cin >> x >> y;
        if(query(1, 3e5, num[x], num[x], 1))
            update(1, 3e5, num[x], num[x], 1, -1);
        else{
            int l = num[x], r = res;
            while(l < r){
                int mid = l + r >> 1;
                if(query(1, 3e5, l, mid, 1) >= 1) r = mid;
                else l = mid + 1;
            }
            update(1, 3e5, num[x], l - 1, 1, 1);
            update(1, 3e5, l, l, 1, -1);
        }
        num[x] = y;
        if(!query(1, 3e5, num[x], num[x], 1))
            update(1, 3e5, num[x], num[x], 1, 1);
        else{
            int l = num[x], r = res + 1;
            while(l < r){
                int mid = l + r >> 1;
                if(query(1, 3e5, l, mid, 1) < mid - l + 1) r = mid;
                else l = mid + 1;
            }
            update(1, 3e5, num[x], l - 1, 1, -1);
            update(1, 3e5, l, l, 1, 1);
        }
        int l = 1, r = 3e5;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(query(1, 3e5, mid, r, 1)) l = mid;
            else r = mid - 1;
        }
        res = l;
        cout << res << endl;
    }
    return 0;
}