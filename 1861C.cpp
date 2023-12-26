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
    string s; cin >> s;
    int win = 0, lose = 1e9, now = 0;
    for(auto x:s){
        if(x == '+'){
            now ++;
            continue;
        }
        if(x == '-'){
            now --;
            win = min(now, win);
            if(now < lose) lose = 1e9;
            continue;
        }
        if(x == '1'){
            if(now < 2) continue;
            if(lose <= now){
                cout << "NO\n";
                return;
            }
            win = now;
            continue;
        }
        if(x == '0'){
            if(win == now || now < 2){
                cout << "NO\n";
                return;
            }
            lose = min(lose, now);
        }
    }
    cout << "YES\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}