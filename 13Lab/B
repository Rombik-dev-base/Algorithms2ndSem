#include <iostream>
#include <string>
#include <fstream>
#include <vector>
 
using namespace std;
 
int main() {
    ifstream inp("search2.in");
    ofstream outp("search2.out");
    string input;
    string input2;
    inp >> input;
    inp >> input2;
    input2 = input +"l"+input2;
    vector<int> ans;
    vector<int> prefix(input2.size(), 0);
    for(int i = 1 ; i < input2.size(); i++){
        int curprefix = prefix[i-1];
        while(curprefix && input2[i] != input2[curprefix])
            curprefix = prefix[curprefix - 1];
        if(input2[i] == input2[curprefix])
            curprefix += 1;
        if(curprefix == input.size())
            ans.push_back(i - 2*input.size() + 1);
        prefix[i] = curprefix;
    }
    outp << ans.size() << '\n';
    for(auto i : ans){
        outp << i << ' ';
    }
}
