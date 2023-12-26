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
    string a, b;
    cin >> a >> b;
    if(a == b){
        cout << '=';
        return;
    }
    int n = a.size(), m = b.size();
    a = ' ' + a, b = ' ' + b;
    if(n < m){
        int up = 0;
        for(int i = 1;i <= n;i ++){
            if(a[i] != b[1]){
                break;
            }
            up = i;
        }
        for(int i = 2;i <= m - n + up;i ++){
            if(b[i] != b[i - 1]){
                cout << "<";
                return;
            }
        }
    }
    if(n > m){
        int up = 0;
        for(int i = 1;i <= m;i ++){
            if(b[i] != a[1]){
                break;
            }
            up = i;
        }
        for(int i = 2;i <= n - m + up;i ++){
            if(a[i] != a[i - 1]){
                cout << '>';
                return;
            }
        }
    }
    cout << "!";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}