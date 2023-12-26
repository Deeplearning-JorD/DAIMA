/*
 * @Author: JorD
 * @LastEditTime: 2022-12-16 19:20:29
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];
    int atk = 2, sum = 0;
    rep(o, 1, m){
        rep(i, 1, n){
            if(a[i] == -1) continue;
            if(a[i] == atk){
                atk ++;
                a[i] = -1;
            }else if(a[i] < atk){
                a[i] = -1;
            }else a[i] -= atk;
        }
        sum += atk;
    }
    cout << sum << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}