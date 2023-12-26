/*
 * @Author: JorD
 * @LastEditTime: 2022-10-08 20:31:02
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
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n;
    cin >> n;
    vector<int> odd, even;
    rep(i, 1, n){
        int x;
        cin >> x;
        if(x & 1){
            odd.push_back(x);
        }else even.push_back(x);
    }
    sort(odd.begin(), odd.end(), [](int x, int y){
        return x > y;
    });
    sort(even.begin(), even.end(), [](int x, int y){
        return x > y;
    });
    int res = 0;
    if(odd.size() >= 2){
        res = odd[0] + odd[1];
    }
    if(even.size() >= 2){
        res = max(res, even[0] + even[1]);
    }
    if(!res) cout << -1;
    else cout << res;
    return;     
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}