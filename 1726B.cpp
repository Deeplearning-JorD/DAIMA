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
    int n, m;
    cin >> n >> m;
    if(m%n == 0){
        cout << "Yes" << endl;
        rep(i, 1, n){
            cout << m / n << ' ';
        }
        cout << endl;
        return;
    }
    if(m < n){
        cout << "No" << endl;
        return;
    }
    vector<int> res(n + 1, 1);
    m -= n;
    if(n&1){
        res[1] += m;
    }else{
        if(m&1){
            bool st = false;
            for(int i = 2;i <= min(n, m);i += 2){
                if(m < i) break;
                if(m%i == 0){
                    rep(j, 1, i) res[i] += m/i;
                    st = true;
                    break;
                }
            }
            if(!st){
                cout << "No" << endl;
                return;
            }
        }else{
            res[1] += m/2;
            res[2] += m/2;
        }
    }
    cout << "Yes" << endl;
    rep(i, 1, n) cout << res[i] << " ";
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}