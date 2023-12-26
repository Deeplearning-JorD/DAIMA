/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 13:17:43
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
int n;
int res;
void Solve(){
    cin >> n;
    for(int i = 0;i <= 400;i ++){
        if(50 * i - n > 9) break;
        for(int j = 0;j <= 1000;j ++){
            if(50 * i + 20 * j - n > 9) break;
            for(int k = 0;k <= 2000;k ++){
                if(50 * i + 20 * j + 10 * k - n > 9) break;
                if(50 * i + 20 * j + 10 * k - n >= 0){
                    res ++;
                }
            }
        }
    }
    cout << res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}