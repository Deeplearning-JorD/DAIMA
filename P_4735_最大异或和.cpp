/*
 * @Author: JorD
 * @LastEditTime: 2023-01-28 14:38:28
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
const int N = 6e5 + 10;
struct Trie{
    int id, cnt;
}tr[N * 30][2];
int idx, root[N];
void dfs(int x, int i, int &clone, int p){
    if(i < 0) return;
    if(!clone) clone = ++ idx;
    int c = x >> i & 1;
    tr[clone][!c] = tr[p][!c];
    tr[clone][c].cnt = tr[p][c].cnt + 1;
    tr[clone][c].id = ++ idx;
    dfs(x, i - 1, tr[clone][c].id, tr[p][c].id);
}
int query(int x, int L, int R, int i){
    if(i < 0) return 0;
    int c = x >> i & 1;
    int cnt = tr[R][!c].cnt - tr[L][!c].cnt;
    if(cnt > 0) return (1 << i) + query(x, tr[L][!c].id, tr[R][!c].id, i - 1);
    else return query(x, tr[L][c].id, tr[R][c].id, i - 1);
}
void Solve(){
    int n, m;
    cin >> n >> m;
    int last = 0;
    dfs(0, 30, root[0], 0);
    rep(i, 1, n){
        int x; cin >> x;
        last ^= x;
        dfs(last, 30, root[i], root[i - 1]);
    }
    while(m --){
        char op; cin >> op;
        if(op == 'A'){
            int x;  cin >> x;
            last ^= x;
            n ++;
            dfs(last, 30, root[n], root[n - 1]);
        }else{
            int l, r, x; cin >> l >> r >> x;
            x ^= last;
            if(l == 1) cout << query(x, 0, root[r - 1], 30) << endl;
            else cout << query(x, root[l - 2], root[r - 1], 30) << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}