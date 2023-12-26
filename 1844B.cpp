/*
 * @Author: JorD
 * @LastEditTime: 2023-07-11 23:02:25
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
    int n; cin >> n;
    vector<int> res(n + 1);
    if(n == 1){
        cout << "1\n";
        return;
    }else if(n == 2){
        cout << "2 1\n";
        return;
    }else if(n == 3){
        cout << "2 1 3\n";
        return;
    }else if(n == 4){
        cout << "2 1 4 3\n";
        return;
    }
    if(n & 1){
        set<int> s;
        rep(i,6,n)s.insert(i);
        res[n/2+1]=1;
        res[n/2]=2;
        res[n] = 3;
        res[n-1]=4;
        res[1] = 5;
        rep(i, 1, n)if(!res[i]){
            res[i]=*s.begin();
            s.erase(s.begin());
        }
    }else{
        set<int> s;
        rep(i,6,n)s.insert(i);
        res[n/2]=1;
        res[n/2-1]=2;
        res[n] = 3;
        res[n-1]=4;
        res[1] = 5;
        rep(i, 1, n)if(!res[i]){
            res[i]=*s.begin();
            s.erase(s.begin());
        }
    }
    rep(i,1,n)cout<<res[i]<<' ';
    cout<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}