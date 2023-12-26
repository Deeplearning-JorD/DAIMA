/*
 * @Author: JorD
 * @LastEditTime: 2022-09-03 20:36:21
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
map<int,int> q;
void Solve(){
    vector<int> a(100), st(100, 1);
    st[3] = st[4] = st[5] = 2;
    string s;
    cin >> s;
    s = ' ' + s;
    if(s[1] == '1'){
        cout << "No" << endl;
        return;
    }
    vector<int> res;
    rep(i, 1, 10){
        if(s[i] == '0') st[q[i]] --;
    }
    rep(i, 1, 7){
        int w = 1;
        if(st[i] == 0) w = 0;
        res.push_back(w);
    }
    while(res.back() == 0 && res.size()) res.pop_back();
    int l = 0;
    while(l < res.size() && res[l] == 0) l++;
    while(l < res.size()){
        if(res[l] == 0){
            cout << "Yes" << endl;
            return;
        }
        l ++;
    }
    cout << "No" << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    q[7] = 1;
    q[4] = 2;
    q[2] = q[8] = 3;
    q[5] = q[1] = 4;
    q[3] = q[9] = 5;
    q[6] = 6;
    q[10] = 7;
    Solve();
    return 0;
}