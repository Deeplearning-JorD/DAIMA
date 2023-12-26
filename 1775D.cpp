/*
 * @Author: JorD
 * @LastEditTime: 2023-01-11 11:56:29
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
int wu;
bool st[N];
int p[N];
int dist[N];
void is_prime(){
    int x = 4e5;
    for(int i=2;i<=x;i++){
        if(!st[i]) p[wu++]=i;
        for(int j=0;p[j]<=x/i;j++){
            /*1.i%pj == 0, pj定为i最小质因子，pj也定为pj*i最小质因子
            2.i%pj != 0, pj定小于i的所有质因子，所以pj也为pj*i最小质因子*/
            st[p[j]*i]=true;
            //这句话保证了i*p[j]的最小质因子都是p[j]
            if(i%p[j]==0) break;   //p[j]一定是i的最小质因子
        }
    }
}
struct node{
    ll dist, id, last;
    bool operator <(const node &ji) const{
        return ji.dist < dist;
    }
};
vector<int> son[N];
int n;
int a[N], pre[N];
int s, t;
void Solve(){
    cin >> n;
    rep(i, 1, n){
        cin >> a[i];
        int x = a[i];
        for(int j = 0;j < wu;j ++){
            int now = p[j];
            if(now > x / now) break;
            if(x % now == 0){
                son[i].push_back(n + now);
                son[n + now].push_back(i);
                while(x % now == 0) x /= now;
            } 
        }
        if(x > 1){
            son[i].push_back(n + x);
            son[n + x].push_back(i);
        }
    }
    cin >> s >> t;
    priority_queue<node> q;
    q.push({0, s, s});
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    vector<bool> vis(n + 1);
    while(q.size()){
        auto [o, now, last] = q.top(); q.pop();
        for(auto x:son[now]){
            if(dist[x] > o + 1){
                dist[x] = o + 1;
                if(x > n) q.push({dist[x], x, last});
                else{
                    pre[x] = last;
                    q.push({dist[x], x, x});
                }
            }
        }
    }
    if(dist[t] == 0x3f3f3f3f){
        cout << -1 << endl;
        return;
    }
    cout << dist[t] / 2 + 1 << endl;
    int now = t;
    vector<int> res;
    res.push_back(now);
    while(pre[now]){
        res.push_back(pre[now]);
        now = pre[now];
    }
    reverse(all(res));
    for(auto x:res){
        cout << x << ' ';
    }
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    is_prime();
    Solve();
    return 0;
}