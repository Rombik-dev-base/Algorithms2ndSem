#include <iostream>
#include <string>
#include <fstream>
#include <vector>
 
using namespace std;
 
int main() {
    ifstream inp("prefix.in");
    ofstream outp("prefix.out");
    string input;
    inp >> input;
    vector<int> prefix(input.size(), 0);
    for(int i = 1 ; i < input.size(); i++){
        int curprefix = prefix[i-1];
        while(curprefix && input[i] != input[curprefix])
            curprefix = prefix[curprefix - 1];
        if(input[i] == input[curprefix])
            curprefix += 1;
        prefix[i] = curprefix;
    }
    for(auto i : prefix){
        outp << i << ' ';
    }
    return 0;
}
