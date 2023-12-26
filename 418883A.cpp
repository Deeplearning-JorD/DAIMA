/*
 * @Author: JorD
 * @LastEditTime: 2023-01-03 14:09:42
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
    int x, y;
    cin >> x >> y;
    if((x + y) & 1){
        cout << "-1 -1\n";
        return;
    }
    int k = x + y >> 1;
    for(int i = -k;i <= k;i ++){
        for(int j = -k;j <= k;j ++){
            int now = abs(i - x) + abs(j - y);
            int ji = abs(i) + abs(j);
            if(now == k && ji == k){
                cout << i << ' ' << j << endl;
                return;
            }
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