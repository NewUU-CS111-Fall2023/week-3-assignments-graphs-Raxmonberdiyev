/*
 * Author: RAXIMBERDI
 * Date:10/31/2023
 * Name:
 */

#include <bits/stdc++.h>

using namespace std;
int main() {
    int num;
    cout<<" Enter the number of genome fragments"<<endl;
    cin >> num;
    cout<<"Enter the descriptions of a fragment"<<endl;
    string str;
    for (int j = 0; j< num; j++) {
        string t;
        cin >> t;
        str=str+t;
    }
    char c[str.size() + 1];
    strcpy(c, str.c_str());
    sort(c, c + str.size());
    char *p = unique(c, c + str.size());
    *p = '\0';
    cout << c << endl;
}