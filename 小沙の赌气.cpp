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
    priority_queue<PII, vector<PII>, greater<PII>> q, qq;
    ll a = 0, b = 0;
    vector<pair<ll, ll>> pa(n + 1), pb(n + 1);
    rep(i, 1, n) cin >> pa[i].first >> pa[i].second;
    rep(i, 1, n) cin >> pb[i].first >> pb[i].second;
    rep(i, 1, n){
        q.push(pa[i]);
        qq.push(pb[i]);
        do{
            auto [x, y] = q.top(); q.pop();
            if(x <= a + 1){
                a = max(a, y);
            }else{
                q.push({x, y});
                break;
            }
        }while(q.size());
        do{
            auto [x, y] = qq.top(); qq.pop();
            if(x <= b + 1){
                b = max(b, y);
            }else{
                qq.push({x, y});
                break;
            }
        }while(qq.size());
        if(a > b){
            cout << "sa_win!\n";
            cout << a - b << endl;
        }else if(a < b){
            cout << "ya_win!\n";
            cout << b - a << endl;
        }else{
            cout << "win_win!\n";
            cout << 0 << endl;
        }
        // cout << a << ' ' << b << endl;
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