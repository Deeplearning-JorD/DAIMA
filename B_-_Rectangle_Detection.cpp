/*
 * @Author: JorD
 * @LastEditTime: 2022-09-17 20:06:38
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
#define rep(i, l, r) for (auto  (i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    vector<vector<char>> f(11, vector<char> (11));
    int A = 100, C = 100, B = 0, D = 0;
    rep(i, 1, 10) rep(j, 1, 10){
        cin >> f[i][j];
        if(f[i][j] == '#'){
            A = min(A, i);
            C = min(C, j);
            B = max(i, B);
            D = max(j, D);
        }
    }
    cout << A << " " << B << endl;
    cout << C << " " << D << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}