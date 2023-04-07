#include<iostream>
using namespace std;
void printPermutation(string str, int idx, string perm) {
    if (str.length() == 0) {
        cout <<"First - "<< perm << endl;
        return;
    }
    
    for (int i = 0; i < str.length(); i++) {
        char currChar = str[i];
        string newStr = str.substr(0, i) + str.substr(i + 1);
        cout<<"\nExtra - "<<newStr<<"\n";
        printPermutation(newStr, idx + 1, perm + currChar);
    }
}

int main() {
    string str = "abc";
    printPermutation(str, 0, "");
    return 0;
}