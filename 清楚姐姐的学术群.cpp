/*
 * @Author: JorD
 * @LastEditTime: 2022-09-02 19:12:25
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
#define rep(i, l, r) for (int (i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (auto(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, m, c, b;
    cin >> n >> m >> c >> b;
    vector<int> last(n + 1);
    vector<vector<int>> a(n + 1);
    int now = 0;
    set<int> s;
    rep(i, 1, m){
        int id, t;
        cin >> id >> t;
        if(now >= c - 1) s.insert(id);
        if(t == 1){
            now ++;
        }else now = 0;
        a[id].push_back(t);
    }
    rep(i, 1, n){
        int sum = 0;
        if(a[i].size() < b) continue;
        for(int j = a[i].size() - 1;j >= 0;j --){
            if(a[i][j] == 1){
                sum ++;
            }else break;
            if(sum == b){
                s.insert(i);
                break;
            }
        }
    }
    cout << s.size() << endl;
    for(auto x:s) cout << x << ' ';
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;


    Solve();
    return 0;
}