/*
 * @Author: JorD
 * @LastEditTime: 2023-01-28 20:49:35
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
const int N = 5e5 + 10;
int tr[N * 10][26];
int cnt[N * 10], idx;
void insert(string& s){
    int p=0;
    for(int i=0;i<s.size();i++){
        int c=s[i]-'a';
        if(tr[p][c]==0)  tr[p][c] = ++idx;
        p = tr[p][c];
        cnt[p]++;
    }
}
int query(string& s){
    int p=0,res=0;
    for(int i=0;i<s.size();i++){
        int c=s[i]-'a';
        if(cnt[p])
        if(!tr[p][c]) return res;
        p=tr[p][c];
        if(cnt[p] == 1) return res;
        res ++;
    }
    return res;
}
string s[N];
void Solve(){
    int n;
    cin >> n;
    rep(i, 1, n){
        cin >> s[i];
        insert(s[i]);
    }
    rep(i, 1, n) cout << query(s[i]) << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}