#include <iostream>
#include <sstream>
#include <map>
using namespace std;

void countWords(string str) {
    stringstream s(str);
    string word;
    string tmp[100];
    int n = 0;
    while(s >> word) {
        tmp[n] = word;     
        n++;
    }
    // sort words
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(tmp[i] > tmp[j])
                swap(tmp[i], tmp[j]);
        }
    }
    int cnt = 1;
    word = tmp[0];
    for(int i=1; i<n; i++) {
        if(word != tmp[i]) {
            cout << word << ": " << cnt << endl;
            cnt = 0;
            word = tmp[i];
        }
        cnt++;
    }
}
int main() {
    string s = "the geeks for the geeks or geeks to the contribution placements.";
    countWords(s);
    return 0;
}
