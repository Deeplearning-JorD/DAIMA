/*
 * @Author: JorD
 * @LastEditTime: 2023-04-05 16:19:12
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
    ll x, y, hp, die;
};
void Solve(){
    int n, T = 0;
    cin >> n;
    vector<node> v;
    while(n --){
        ll op, x, y, hp, atk, r;
        cin >> op;
        if(op == 1){
            cin >> x >> y >> hp;
            v.push_back({x, y, hp, 1});
        }else{
            cin >> x >> y >> atk >> r;
            ll dist = 2e18, id = -1, idx = 0;
            for(auto [sx, sy, hp, die]:v)if(hp > 0){
                if(dist > (sx - x) * (sx - x) + (sy - y) * (sy - y)){
                    dist = (sx - x) * (sx - x) + (sy - y) * (sy - y);
                    id = idx;
                }
                idx ++;
            }else idx ++;
            if(id < 0){ 
                v.push_back({x, y, -1, 1});
                continue;
            }
            x = v[id].x, y = v[id].y;
            int D = 1;
            for(auto &[sx, sy, hp, die]:v)if(hp > 0){
                if(r * r >= (sx - x) * (sx - x) + (sy - y) * (sy - y)){
                    hp -= atk * 3;
                    if(hp <= 0){
                        die = 0;
                    }else{
                        D = 0;
                    }
                }
            }
            v.push_back({x, y, -1, D});
        }
    }
    for(auto w:v){
        if(w.die) cout << "Yes\n";
        else cout << "No\n";
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