/*
 * @Author: JorD
 * @LastEditTime: 2023-01-10 20:00:35
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
    map<int,int> f;
    vector<vector<int>> a(n + 1);
    rep(i, 1, n){
        int k;
        cin >> k;
        a[i].resize(k + 1);
        rep(j, 1, k){
            cin >> a[i][j];
            f[a[i][j]] ++;
        }
    }
    rep(i, 1, n){
        int cnt = 0, idx = 0;
        for(auto &x:a[i]){
            if(!x) continue;
            cnt ++;
            if(f[x] >= 2) idx ++;
            else{
                idx = -1;
                break;
            }
        }
        if(cnt == idx){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}