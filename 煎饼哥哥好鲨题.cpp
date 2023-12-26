/*
 * @Author: JorD
 * @LastEditTime: 2022-11-19 12:09:54
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
    vector<int> a(4);
    rep(i, 1, n){
        string s;
        cin >> s;
        if(s == "AC") a[0] ++;
        else if(s == "WA") a[1] ++;
        else if(s == "TLE") a[2] ++;
        else a[3] ++;
    }
    cout << "AC x " << a[0] << endl;
    cout << "WA x " << a[1] << endl; 
    cout << "TLE x " << a[2] << endl;
    cout << "RE x " << a[3] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}