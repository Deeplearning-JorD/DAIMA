/*
 * @Author: JorD
 * @LastEditTime: 2023-10-12 22:28:58
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 2e5 + 10;
int f[N];
int find(int x){
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}
struct node{
    int a, b, c, i;
    bool operator <(const node &ji)const{
        return i < ji.i;
    }
};
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<int> h(n + 1);
    rep(i, 1, n){
        f[i] = i;
        cin >> h[i];
    }
    vector<vector<int>> son(n + 1);
    vector<pair<int,int>> e(m);
    for(auto &[x, y]:e) cin >> x >> y;
    sort(e.begin(), e.end(), [&](pair<int,int> x, pair<int,int> y){
        return max(h[x.first], h[x.second]) < max(h[y.first], h[y.second]);
    });
    cin >> m;
    vector<int> res(m + 1);
    vector<set<node>> s(n + 1);
    rep(i, 1, m){
        int a, b, c; cin >> a >> b >> c;
        if(a == b) res[i] = 1;
        s[a].insert((node){a, b, c, i});
        s[b].insert((node){a, b, c, i});
    }   
    for(auto [x, y]:e){
        int now = max(h[x], h[y]);
        x = find(x), y = find(y);
        if(x == y) continue;
        if(s[x].size() < s[y].size()) swap(x, y);
        for(auto [a, b, c, i]:s[y]){
            if(find(a) == x && find(b) == y || find(a) == y && find(b) == x){
                if(now - h[a] <= c){
                    res[i] = 1;
                }
                s[x].erase({a, b, c, i});
            }else s[x].insert({a, b, c, i});
        }
        f[y] = x;
    }
    rep(i, 1, m)if(res[i])cout << "YES\n";
    else cout << "NO\n";
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