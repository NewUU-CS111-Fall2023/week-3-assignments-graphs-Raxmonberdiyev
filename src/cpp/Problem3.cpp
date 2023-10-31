/*
 * Author: RAXIMBERDI
 * Date:10/31/2023
 * Name:
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    vector<int> v;
  cout<<"Enter current number"<<endl;
    cin >> a;
    cout<<" Enter the number B is transformed by current number"<<endl;
    cin>> b;
    v.push_back(b);
    while (a < b) {
        if (b % 2 == 0) {
            b=b/ 2;
            v.push_back(b);
        }
        else if (b % 10 == 1) {
            b /= 10;
            v.push_back(b);
        } else {
            break;
        }
    }


    if (a == b) {
        cout << "YES\n";
        cout<<v.size()<<endl;
        for (int i = v.size()-1 ; i >= 0; i--) {

            cout << v[i] << " ";

        }
    } else {
        cout << "NO";
    }

}