/*
 * @Author: JorD
 * @LastEditTime: 2023-03-21 18:07:08
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
struct node{
    int x, d, j;
    bool operator <(const node &ikun)const{
        return ikun.x > x;
    }
};
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<node> a(n + 1);
    rep(i, 1, n) cin >> a[i].x;
    rep(i, 1, n){
        char x; cin >> x;
        a[i].d = x == 'R';
        a[i].j = i;
    }
    sort(a.begin() + 1, a.end());
    vector<int> res(n + 1, -1);
    vector<int> odd, odd1;
    queue<int> q, qq;
    for(int i = 1;i <= n;i ++){
        auto [x, d, j] = a[i];
        if(d == 0){
            if(x & 1){
                if(!odd1.empty()){
                    auto t = odd1.back();
                    int y = a[t].x;
                    res[a[t].j] = res[j] = x - y >> 1;
                    odd1.pop_back();
                }else if(!q.empty()){
                    auto t = q.front(); q.pop();
                    int y = a[t].x;
                    res[a[t].j] = res[j] = x + y >> 1;
                }else{
                    q.push(i);
                }
            }else{
                if(!odd.empty()){
                    auto t = odd.back();
                    int y = a[t].x;
                    res[a[t].j] = res[j] = x - y >> 1;
                    odd.pop_back();
                }else if(!qq.empty()){
                    auto t = qq.front(); qq.pop();
                    int y = a[t].x;
                    res[a[t].j] = res[j] = x + y >> 1;
                }else{
                    qq.push(i);
                }
            }
        }else{
            if(x & 1) odd1.push_back(i);
            else odd.push_back(i);
        }
    }
    while(q.size()) q.pop();
    while(qq.size()) qq.pop();
    for(int i = n;i >= 1;i --){
        if(res[a[i].j] != -1) continue;
        auto [x, d, j] = a[i];
        if(d == 0) continue;
        if(x & 1){
            if(!q.empty()){
                auto t = q.front(); q.pop();
                int y = a[t].x;
                res[a[t].j] = res[j] = 2 * m - x - y >> 1;
            }else q.push(i);
        }else{
            if(!qq.empty()){
                auto t = qq.front(); qq.pop();
                int y = a[t].x;
                res[a[t].j] = res[j] = 2 * m - x - y >> 1;
            }else qq.push(i);
        }
    }
    vector<int> v1, v2;
    for(int i = 1;i <= n;i ++){
        if(res[a[i].j] != -1) continue;
        auto [x, d, j] = a[i];
        if(d == 0) continue;
        if(x & 1) v1.push_back(i);
        else v2.push_back(i);
    }
    for(int i = 1;i <= n;i ++){
        if(res[a[i].j] != -1) continue;
        auto [x, d, j] = a[i];
        if(d == 1){
            if(x & 1) v1.pop_back();
            else v2.pop_back();
            continue;
        } 
        if(x & 1){
            if(v1.size()){
                auto t = v1.back();
                int y = a[t].x;
                res[a[t].j] = res[j] = 2 * m + x - y >> 1;
                v1.pop_back();
            }
        }else if(v2.size()){
            auto t = v2.back();
            int y = a[t].x;
            res[a[t].j] = res[j] = 2 * m + x - y >> 1;
            v2.pop_back();
        }
    }
    rep(i, 1, n) cout << res[i] << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}