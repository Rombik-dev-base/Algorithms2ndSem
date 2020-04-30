#include <iostream>
#include <string>
#include <vector>
#include <fstream>
 
using namespace std;
 
int main() {
    int power;
    cin >> power;
    string inp;
    cin >> inp;
    inp += "#";
    vector<int> prefix(inp.size(),0);
    for(int i = 1; i < prefix.size(); i++){
        int curprefix = prefix[i-1];
        while(curprefix && inp[i] != inp[curprefix])
            curprefix = prefix[curprefix - 1];
        if(inp[i] == inp[curprefix])
            curprefix += 1;
        prefix[i] = curprefix;
    }
    vector < vector<int> > ans (inp.size(), vector<int> (power,0));
    for (int i = 0; i < inp.size(); i++) {
        for (char c = 'a'; c < 'a' + power; c++) {
            if (i > 0 && c != inp[i]) {
                ans[i][c - 'a'] = ans[prefix[i - 1]][c - 'a'];
            }
            else {
                ans[i][c - 'a'] = i + (c == inp[i]);
            }
        }
    }
    for(auto i : ans){
        for(auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
