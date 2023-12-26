/*
 * @Author: JorD
 * @LastEditTime: 2023-06-07 00:49:34
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
void Solve(){
    string s1, s2; cin >> s1 >> s2;
    int n = s1.size();
    string now = " " + s1 + s2;
    vector<int> a(n + 1), b(n + 1);
    rep(i, 1, n){
        a[i] = i;
        b[i] = n + i;
    }
    int T, t;
    cin >> t >> T;
    set<int> v, vv;
    rep(i, 1, n){
        if(now[a[i]] != now[b[i]]){
            v.insert(a[i]);
            v.insert(b[i]);
            vv.insert(a[i]);
            vv.insert(b[i]);
        }
    }
    vector<set<int>> s(T + 1);
    rep(i, 1, T){
        for(auto x:s[i]){
            if(vv.count(x))
            v.insert(x);
        }
        int op;
        cin >> op;
        if(op == 1){
            int x; cin >> x;
            if(v.count(a[x])){
                v.erase(a[x]);
                v.erase(b[x]);
                if(i + t <= T){
                    s[i + t].insert(a[x]);
                    s[i + t].insert(b[x]);
                }
            }
        }else if(op == 2){
            int x, y, sx, sy;
            cin >> x >> y >> sx >> sy;
            if(now[a[y]] != now[b[y]]){
                vv.erase(a[y]);
                vv.erase(b[y]);
            }
            if(now[a[sy]] != now[b[sy]]){
                vv.erase(a[sy]);
                vv.erase(b[sy]);
            }
            if(now[a[y]] != now[b[y]]){
                v.erase(a[y]);
                v.erase(b[y]);
            }
            if(now[a[sy]] != now[b[sy]]){
                v.erase(a[sy]);
                v.erase(b[sy]);
            }
            if(x == 1){
                if(sx == 1){
                    swap(a[y], a[sy]);
                }else swap(a[y], b[sy]);
            }else{
                if(sx == 1){
                    swap(b[y], a[sy]);
                }else swap(b[y], b[sy]);
            }
            if(now[a[y]] == now[b[y]]){
                vv.erase(a[y]);
                vv.erase(b[y]);
            }else{
                vv.insert(a[y]);
                vv.insert(b[y]);
            }
            if(now[a[sy]] == now[b[sy]]){
                vv.erase(a[sy]);
                vv.erase(b[sy]);
            }else{
                vv.insert(a[sy]);
                vv.insert(b[sy]);
            }
            if(now[a[y]] == now[b[y]]){
                v.erase(a[y]);
                v.erase(b[y]);
            }else{
                v.insert(a[y]);
                v.insert(b[y]);
            }
            if(now[a[sy]] == now[b[sy]]){
                v.erase(a[sy]);
                v.erase(b[sy]);
            }else{
                v.insert(a[sy]);
                v.insert(b[sy]);
            }
        }else{
            if(v.size()) cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}