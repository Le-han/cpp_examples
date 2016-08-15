/**
�������� ���������, ������� ��������� �� ������������ �������� ������ �������� ����� � ����� �����������,
������������� ������� �������� �����, ��������������� ���� � �������������� ����.
���������� ��� ����� ����� ��������� ������� �������������� ��� ��������� � ����������� (��� ����� ��������).
����� � ������������ ����������� ���������, ��� ������� ������������ ������� isspace() ��� ispunct() ����������
��������� ��������.
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    double my_word = 0;
    double cnt = 0; // ������� �������������� � / cnt
    string word, buf, cur;
    cin >> word;
    getline(cin, buf);
    istringstream iss(buf);
    while (iss >> cur){
        if (ispunct(cur[cur.size() - 1])){
            ++cnt;
            cur.erase(cur.size() - 1, 1);
        }
        if(strcmp(cur.c_str(), word.c_str()) == 0){
            ++my_word;
        }
    }
    double res = my_word / cnt;
    cout << res;
    return 0;
}


