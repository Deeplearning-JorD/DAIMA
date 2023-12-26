/*
 * @Author: JorD
 * @LastEditTime: 2023-05-07 14:55:36
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
double ff(string &s){
    double res = 0, r = 0;
    bool st = false;
    double p = 10, pp = 0.1;
    for(int i = 0;i < s.size();i ++){
        if(s[i] == '+' || s[i] == '-') continue;
        if(s[i] == '.'){
            st = true;
            continue;
        }
        if(!st){
            res = res * p + s[i] - '0';
        }else{
            r += (s[i] - '0') * pp;
            pp *= 0.1;
        }
    }
    res += r;
    if(s[0] == '-') res *= -1;
    return res;
}
void Solve(){
    int n;
    string s;
    cin >> n >> s;
    double b = ff(s);
    vector<vector<double>> a(n + 1, vector<double> (n + 1));
    rep(i, 1, n){
        rep(j, 1, n){
            cin >> s;
            a[i][j] = ff(s);
        }
        a[i][0] = - 10;
    }
    vector<int> ne(n + 1);
    rep(i, 1, n){
        int id = 0;
        rep(j, 1, n)if(i != j && a[i][j] >= b){
            if(a[i][j] > a[i][id]) id = j;
        }
        if(id) ne[i] = id;
    }
    vector<bool> st(n + 1);
    int cnt = 0;
    rep(i, 1, n)if(!st[i] && ne[i]){
        int j = i;
        while(!st[j]){
            st[j] = true;
            j = ne[j];
        }
        if(j == i) continue;
        cnt ++;
    }
    rep(i, 1, n) cnt += !st[i];
    if(n == 1) cout << "kono jinsei, imi ga nai!\n";
    else if(!cnt) cout << "wish you the best in your search\n";
    else cout << "hbxql\n";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}