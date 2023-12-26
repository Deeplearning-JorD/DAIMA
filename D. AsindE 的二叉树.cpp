/*
 * @Author: JorD
 * @LastEditTime: 2023-05-04 00:55:34
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
// #define endl '\n'
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
    ll k;
    cin >> k;
    ll root = 1, depth = 0;
    while(1){
        if(root << 1 >= (1ll << k)){
            cout << "! " << root << ' ' << root << endl;
            break;
        }
        cout << "? " << root << " " << (root << 1) << endl;
        ll x; cin >> x;
        ll num = 1ll << (k - depth);
        num --;
        if(x == (num + 1) / 2){
            cout << "? " << root << " " << (root << 1|1) << endl;
            cin >> x;
            if(x == 1){
                cout << "! " << root << ' ' << (root << 1|1) << endl;
                break;
            }  
            root = root << 1|1;
            depth ++;
            if(root >= (1ll << k - 1)){
                cout << "! " << root << ' ' << root / 2 << endl;
                break;
            }
            continue;
        }
        root = root << 1;
        if(root >= (1ll << k - 1)){
            cout << "! " << root << ' ' << root / 2 << endl;
            break;
        }
        depth ++;
    }
    return;
}
int main(){
    // std::ios::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}