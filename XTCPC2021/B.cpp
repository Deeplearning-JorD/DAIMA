/*
 * @Author: JorD
 * @LastEditTime: 2023-04-12 21:18:43
 */
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
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
string a, b;
int calc(string &s){
    int cnt = 0;
    for(char c:s){
        cnt += c == '1';
    }
    return cnt;
}
void Solve(){
    reverse(all(a));
    reverse(all(b));
    int n = a.size(), m = b.size();
    int sum0 = 0, sum1 = 0;
    int id = n - 1;
    bool buer = 0;
    for(int i = n - 1;i >= 0;i --){
        if(i <= m - 1){
            sum1 += b[i] == '1';
        }
        if(a[i] == '1' && !buer)if(sum1 <= sum0){
            id = i;
        }
        sum0 += a[i] == '1';
        if(sum0 < sum1){
            buer = 1;
        }
    }

    ll res = 0;
    if(buer){
    for(int i = 0;i < id;i ++){
        if(a[i] == '1') res += i + 1;
    } 
    a[id] = '0';
    for(int i = 0;i < id;i ++){
        a[i] = '1';
    }
    res ++;
    }
    // cout << a << '\n' << b << endl;
    int cnt0 = calc(a), cnt1 = calc(b);
    id = 0;
    while(cnt0 > cnt1){
        while(a[id] != '1') id ++;
        a[id] = '0';
        res += id + 1;
        cnt0 --;
    }
    cout << a << endl << b << endl;
    // cout << res << "???\n";
    for(int i = 0, j = 0;i < m && j < n;i ++, j ++){
        while(i < m && b[i] == '0') i ++;
        while(j < n && a[j] == '0') j ++;
        if(i >= m || j >= n) break;
        res += j - i;
    }
    // cout << id << ' ';
    cout << res << endl;
    // cout << a << '\n' << b << endl;
    return; 
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; 
    while(cin >> a >> b)
    Solve();
    return 0;
}