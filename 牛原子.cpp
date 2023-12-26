/*
 * @Author: JorD
 * @LastEditTime: 2022-10-02 19:23:17
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
vector<string> s[20];
string ss = "1s 2s 2p 3s 3p 4s 3d 4p 5s 4d 5p 6s 4f 5d 6p 7s 5f 6d 7p";
map<char,int> q;
string get(int x){
    return to_string(x);
}
void Solve(){
    int n;
    cin >> n;
    int l = 0;
    vector<string> res;
    rep(i, 1, 19){
        char x = ss[l], c = ss[l + 1];
        int w = q[c];
        string now = "  ";
        now[0] = x;
        now[1] = c;
        if(n >= w) now += get(w);
        else now += get(n);
        n -= w;
        res.push_back(now);
        l += 3;
        if(n <= 0) break;
    }
    sort(res.begin(), res.end(), [&](string a, string b){
        if(a[0] == b[0]) return q[a[1]] < q[b[1]];
        return a[0] < b[0];
    });
    for(auto x:res) cout << x << ' ';
    cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    q['s'] = 2;
    q['d'] = 10;
    q['f'] = 14;
    q['p'] = 6;
    while(t --)
    Solve();
    return 0;
}