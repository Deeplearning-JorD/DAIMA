#pragma GCC optimize(2)
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
    ll c, cnt = 0; cin >> c;
    while(c % 2 == 0){c >>= 1; cnt ++;}
    if(cnt == 1){
        if(c == 1) cout << "Ashishgup\n";
        else{
            bool st = true;
            for(int i = 2;i <= c / i;i ++){
                if(c % i == 0){
                    st = false;
                    break;
                }
            }
            if(st) cout << "FastestFinger\n";
            else cout << "Ashishgup\n";
        }
    }else{
        if(c == 1) cout << "FastestFinger\n";
        else cout << "Ashishgup\n";
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