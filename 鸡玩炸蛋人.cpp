/*
 * @Author: JorD
 * @LastEditTime: 2023-01-16 16:47:22
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
const int N = 2e5 + 10;
vector<int> son[N];
int n, m, idx;
int c[N], col[N];
int cnt;
bool flag;
int sum, ji;
void dfs(int now){
    col[now] = idx;
    cnt ++;
    ji += c[now] ? 1:0;
    for(auto x:son[now])if(!col[x]){
        dfs(x);
    }
}
void Solve(){
    cin >> n >> m;
    rep(i, 1, m){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    rep(i, 1, n){
        cin >> c[i];
        sum += c[i] ? 1:0;
    }
    ll res = 0;
    rep(i, 1, n)if(!col[i]){
        cnt = 0;
        idx ++;
        flag = true;
        dfs(i);
        if(ji != sum && ji){
            cout << 0 << endl;
            return;
        }
        if(ji == sum && sum){
            cout << 1ll * cnt * cnt << endl;
            return;    
        }else
        res += 1ll * cnt * cnt;
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}