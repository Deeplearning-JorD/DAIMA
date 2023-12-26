/*
 * @Author: JorD
 * @LastEditTime: 2022-12-25 15:05:40
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
    int n;
    cin >> n;
    vector<tuple<int,int,int,int>> p;
    rep(i, 1, n){
        int a, b, c;
        cin >> a >> b >> c;
        p.push_back({a, b, c, i});
    }
    int mm;
    cin >> mm;
    rep(m, 1, mm){
        int t;
        cin >> t;
        while(t --){
            int id, tt;
            cin >> id >> tt;
            vector<tuple<int,int,int,int>> q;
            for(auto [a, b, c, d] : p){
                if(a == id){
                    q.push_back({a, b, c, d});
                }
            }
            
            while(tt --){
                int col;
                cin >> col;
                for(auto [a, b, c, d]:q){
                    if(col == b){
                        
                    }
                }
            }
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