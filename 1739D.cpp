/*
 * @Author: JorD
 * @LastEditTime: 2022-10-02 16:11:52
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
void Solve(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>> son(n + 1);
    rep(i, 2, n){
        int x; cin >> x;
        son[x].push_back(i);
    }
    vector<int> depth(n + 1);
    int cnt = 0;
    function<void(int,int,int)> dfs = [&](int now, int fa, int mid){
        depth[now] = 1; 
        for(auto x:son[now]){
            if(x == fa) continue;
            dfs(x, now, mid);
            depth[now] = max(depth[now], depth[x] + 1); 
        }
        if(fa > 1&&depth[now] == mid){
            cnt ++;
            depth[now] = 0;
        }
    };
    int l = 1, r = n - 1;
    while(l < r){
        int mid = l + r >> 1;
        cnt = 0;
        dfs(1, 0, mid);
        if(cnt <= k) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
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