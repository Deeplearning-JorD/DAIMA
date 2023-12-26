/*
 * @Author: JorD
 * @LastEditTime: 2022-11-18 23:57:02
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
int js(string s){
    reverse(s.begin(), s.end());
    int res = 0, idx = 0;
    while(idx < siz(s)&&s[idx] == '0'){
        idx ++;
        res ++;
    }
    return res;
}
ll get(string s){
    ll res = 0;
    for(auto x:s){
        res = res * 10 + x - '0';
    }
    return res;
}
bool cmp(ll x, ll y){
    // cout << x << ' ' << y << endl;
    int cnt1 = js(to_string(x)), cnt2 = js(to_string(y));
    // cout << cnt1 << ' ' << cnt2 << endl;
    if(cnt1 == cnt2) return x > y;
    return cnt1 > cnt2;
}
bool check(string s){
    reverse(s.begin(), s.end());
    int res = 0, idx = 0;
    while(idx < siz(s)&&s[idx] == '0'){
        idx ++;
        res ++;
    }
    if(idx < siz(s)&&s[idx] == '5') return true;
    return false;
}
void Solve(){
    ll n, m;
    cin >> n >> m;
    string mm = to_string(m);
    vector<ll> res;
    res.push_back(n * m);
    string z1 = "", z2 = "";
    if(n % 2 == 0){
        string now = "5";
        for(int i = 1;i < siz(mm);i ++)
            now += "0";
        res.push_back(get(now) * n);
        for(char i = '1';i <= '9';i ++){
            string ji = i + now;
            if(ji <= mm) res.push_back(get(now) * n);
        }
    }else if(check(to_string(n))){
        string now = "2";
        for(int i = 1;i < siz(mm);i ++)
            now += "0";
        res.push_back(get(now) * n);
        for(char i = '1';i <= '9';i ++){
            string ji = i + now;
            if(ji <= mm) res.push_back(get(now) * n);
        }
    }else{
        for(char i = '1';i <= '9';i ++){
            string now = "" + i;
            for(int j = 1;j < siz(mm);j ++)
                now += " ";
            if(now <= mm) res.push_back(get(now) * n);
        }
    } 
    // cout << 10050 * 12000 << endl;
    sort(res.begin(), res.end(), cmp);
    cout << *res.begin() << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t --)
    Solve();
    return 0;
}