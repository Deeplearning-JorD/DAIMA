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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int id = 0;
    for(int i = 0;i < s.size();i ++){
        if(s[i] == '*') id = i;
    }
    int i = id;
    while(i >= 0 && s[i] != '|') i --;
    int j = id;
    while(j < s.size() && s[j] != '|') j ++;
    if(s[i] == s[j] && s[i] == '|') cout << "in";
    else cout << "out";
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}