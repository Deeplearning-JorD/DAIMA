/*
 * @Author: JorD
 * @LastEditTime: 2022-12-31 23:09:28
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
    srand(time(0));
    int x;
    cin >> x;
    vector<int> a(6);
    rep(i, 1, 6) a[i - 1] = i;
    set<vector<int>> s;
    do{ 
        vector<int> v;
        for(auto x:a){
            if(x <= 3) v.push_back(1);
            else v.push_back(2);
        }
        s.insert(v);
    }while(next_permutation(a.begin(), a.end()));
    vector<vector<int>> ww;
    for(auto u:s){
        ww.push_back(u);
    }   
    auto f = ww[rand()%20];
    if(x == 1){
        cout << 1 << ' ' << f[0] << endl;
    }else if(x == 2){
        cout << 1 << ' ' << f[1] << endl;
    }else if(x == 3){
        cout << 1 << ' ' << f[2] << endl;
    }else if(x == 4){
        cout << 1 << ' ' << f[3] << endl;
    }else if(x == 5){
        cout << 1 << ' ' << f[4] << endl;
    }else cout << 1 << ' ' << f[5] << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}