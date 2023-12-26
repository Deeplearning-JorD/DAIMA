/*
 * @Author: JorD
 * @LastEditTime: 2023-08-06 18:09:02
 * how to Get
 */
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<vector<int>> son(16);
    for(int i = 0;i < (1 << 14);i ++){
        int cnt = 0;
        for(int j = 0;j < 14;j ++){
            cnt += i >> j & 1;
        }
        son[cnt].push_back(i);
    }
    ll sum = 0;
    for(int i = 0;i <= 14;i ++){
        for(int j = 0;j <= 14;j ++){
            sum += (int)(son[i].size()) * (int)(son[j].size());
        }
    }
    cout << sum;
    return 0;
}