/*
 * @Author: JorD
 * @LastEditTime: 2022-10-16 15:21:48
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
    string s;
    cin >> s;
    int n = siz(s);
    s = ' ' + s;
    function<int(int,int)> dfs = [&](int l, int r) -> int{
        if(l > r||l < 1||r > n) return 0;
        // if(s[l] == '('&&s[r] == ')') return dfs(l + 1, r - 1);
        int num = 0, a, b;
        int idx = 0;
        // rep(i, l, r){
        //     if(s[i] == '(') idx ++;
        // }
        // if(idx == 1&&s[l] == '(' && s[r] == ')') return dfs(l + 1, r - 1);
        rep(i, l, r){
            if(s[i] == '+'){
                if(s[l] == '(' && s[i - 1] == ')') a = dfs(l + 1, i - 2);
                else a = dfs(l, i - 1);
                if(s[i + 1] == '(' && s[r] == ')') b = dfs(i + 2, r - 1);
                else b = dfs(i + 1, r);
                return a + b;
            }
            if(s[i] == '-'){
                if(s[l] == '(' && s[i - 1] == ')') a = dfs(l + 1, i - 2);
                else a = dfs(l, i - 1);
                if(s[i + 1] == '(' && s[r] == ')') b = dfs(i + 2, r - 1);
                else b = dfs(i + 1, r);
                return a - b;
            }
        }
        per(i, r, l){
            if(s[i] == '*'){
                if(s[l] == '(' && s[i - 1] == ')') a = dfs(l + 1, i - 2);
                else a = dfs(l, i - 1);
                if(s[i + 1] == '(' && s[r] == ')') b = dfs(i + 2, r - 1);
                else b = dfs(i + 1, r);
                return a * b;
            }
            if(s[i] == '/'){
                if(s[l] == '(' && s[i - 1] == ')') a = dfs(l + 1, i - 2);
                else a = dfs(l, i - 1);
                if(s[i + 1] == '(' && s[r] == ')') b = dfs(i + 2, r - 1);
                else b = dfs(i + 1, r);
                return a / b;
            }
        }
        rep(i, l, r){
            if(s[i]=='('||s[i]==')') continue;
            num *= 10;
            num += s[i] - '0';
            // cout << s[i];
        }
        cout << endl;
        // cout << num << endl;
        return num;
    };  
    cout << dfs(1, n); 
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;
    Solve();
    return 0;
}