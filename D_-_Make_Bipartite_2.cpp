/*
 * @Author: JorD
 * @LastEditTime: 2022-12-17 21:32:35
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
const int N = 1e6 + 10;
vector<int> son[N];
int st[N];
ll cnt1, cnt2;
bool flag;
vector<int> v;
void dfs(int now, int col){
    st[now] = col;
    v.push_back(now);
    if(col == 1) cnt1 ++;
    else cnt2 ++;
    for(auto x:son[now]){
        if(st[x] == col){
            cout << 0;
            exit(0);
        }
        if(st[x]) continue;
        dfs(x, 3 - col);
    }
}
int vis[N];
void Solve(){
    int n, m;
    cin >> n >> m;
    while(m --){
        int x, y;
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    ll res = 0;
    ll sum = 0;
    vector<ll> vv;
    rep(i, 1, n){
        if(st[i]) continue;
        flag = true;
        cnt1 = cnt2 = 0;
        v.clear();
        dfs(i, 1);
        if(flag){
            for(auto x:v){
                if(st[x] == 1){
                    res += cnt2 - son[x].size();
                }else res += cnt1 - son[x].size();
            }
            vv.push_back(cnt1 + cnt2);
            sum += cnt1 + cnt2;
        }
    }
    for(auto x:vv){
        res += (sum - x) * x;
    }
    cout << res / 2 << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}