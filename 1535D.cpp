/*
 * @Author: JorD
 * @LastEditTime: 2023-01-04 22:28:34
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
const int N = 1 << 18|1;
int n;
int tr[N << 2], idx;
int res[N << 2], f[N << 2];
int ls[N << 2], rs[N << 2];
string s;
void build(int p, int l, int r){
    if(l == r) return;
    ls[p] = l, rs[p] = r;
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1|1, mid + 1, r);
}
int dfs(int now, int l, int r){
    if(l == r){
        return 1;
    }
    if(res[now]) return res[now];
    int mid = l + r >> 1;
    if(s[tr[now]] == '?'){
        res[now] = dfs(now << 1, l, mid) + dfs(now << 1|1, mid + 1, r);
    }else if(s[tr[now]] == '1'){
        res[now] = dfs(now << 1|1, mid + 1, r);
    }else{
        res[now] = dfs(now << 1, l, mid);
    }
    return res[now];
}
void Solve(){
    cin >> n;
    cin >> s;
    s = ' ' + s;
    vector<int> q;
    q.push_back(1);
    idx = 1 << n;
    rep(i, 1, n){
        vector<int> ls;
        for(auto x:q){
            ls.push_back(x << 1);
            ls.push_back(x << 1|1);
        }
        reverse(q.begin(), q.end());
        for(auto x:q){
            tr[x] = -- idx;
            f[idx] = x;
        }
        swap(q, ls);
    }
    build(1, 1, 1 << n);
    dfs(1, 1, 1 << n);
    int m;
    cin >> m;
    while(m --){
        int x;
        char c;
        cin >> x >> c;
        s[x] = c;
        int now = f[x];
        while(now){
            int l = ls[now], r= rs[now];
            int mid = l + r >> 1;
            if(s[tr[now]] == '?'){
                res[now] = dfs(now << 1, l, mid) + dfs(now << 1|1, mid + 1, r);
            }else if(s[tr[now]] == '1'){
                res[now] = dfs(now << 1|1, mid + 1, r);
            }else{
                res[now] = dfs(now << 1, l, mid);
            }  
            now >>= 1;
        }
        cout << res[1] << endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int t; cin>>t; while(t --)
    Solve();
    return 0;
}