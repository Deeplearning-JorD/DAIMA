/*
 * @Author: JorD
 * @LastEditTime: 2022-09-07 00:51:02
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
    string s;
    cin >> s;
    s = ' ' + s;
    vector<int> num(2*n + 2);
    vector<int> last(2*n + 2);
    set<int> q;
    vector<int> col(2*n + 1);
    rep(i,0,2*n)col[i] = i;
    col[0]=1;
    auto find = [&](int x){
        while(x!=col[x]) x=col[x]=col[col[x]];
        return x;
    };
    rep(i, 1, 2*n){
        num[i] = num[i - 1];
        num[i] += ((s[i] =='(')?1:-1);
        // q.insert(num[i]);
        if(s[i-1]==')'&&s[i]=='(')col[find(i)]=col[find(i-1)];
        if(last[num[i]]||num[i]==0)
        if('('==s[last[num[i]] + 1]&&s[i]==')')
        {
            col[find(i)] = col[find(last[num[i]] + 1)];
            // cout << i << " " << last[num[i]]  + 1 << endl;
        }
        last[num[i]] = i;
    }
    rep(i,1,2*n)q.insert(find(i));
    // cout << endl;
    cout << q.size() << endl;
    // for(auto x:q) cout << x << " ";
    // cout << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}