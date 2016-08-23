#include <bits/stdc++.h>

using namespace std;

int main()
{
    string buf, find_str;
    cout << "INPUT string: ";
    getline(cin, buf);
    cout << "INPUT find string: ";
    getline(cin, find_str);
    cout << endl;
    size_t cnt = 0;
    size_t i = buf.find(find_str);
    while(i != string::npos){
        cout <<buf.substr(i, find_str.size()) <<" position: "<< i <<endl;
        i = buf.find(find_str, i + find_str.size());
    }
    return 0;
}
