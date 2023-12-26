/*
 * @Author: JorD
 * @LastEditTime: 2022-12-06 02:25:42
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
map<pair<string,string>, int> q;
void Solve(){
    int n;
    cin >> n;
    set<string> s;
    while(n --){
        string ss; cin >> ss;
        s.insert(ss);
    }
    int res = 0;
    for(auto x:s){
        for(auto y:s){
            res += q[{x, y}];
        }
    }
    cout << res << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    q[{"cryo","pyro"}] = 1;
    q[{"cryo","hydro"}] = 1;
    q[{"cryo","electro"}] = 1;
    q[{"hydro","pyro"}] = 1;
    q[{"hydro","electro"}] = 1;
    q[{"hydro","dendro"}] = 1;
    q[{"pyro","electro"}] = 1;
    q[{"pyro","dendro"}] = 1;
    q[{"electro","dendro"}] = 1;
    q[{"anemo","cryo"}] ++;
    q[{"anemo","hydro"}] ++;
    q[{"anemo","pyro"}] ++;
    q[{"anemo","electro"}] ++;
    q[{"geo","cryo"}] ++;
    q[{"geo","hydro"}] ++;
    q[{"geo","pyro"}] ++;
    q[{"geo","electro"}] ++;
    Solve();
    return 0;
}