/*
 * @Author: JorD
 * @LastEditTime: 2023-01-27 22:51:28
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
    int n, s, r;
    cin >> n >> s >> r;
    cout << s - r << ' ';
    int mx = s - r;
    s -= s - r;
    for(int i = 2, j = n - 2;i <= n;i ++, j --){
        for(int k = 1;k <= 6;k ++){
            if(s - k >= j && s - k <= j * mx){
                s -= k;
                cout << k << ' ';
                break;
            }
        }
    }
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