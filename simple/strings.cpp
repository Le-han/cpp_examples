/**
Написать программу, которая считывает со стандартного входного потока заданное слово и набор предложений,
разделителями которых являются точка, восклицательный знак и вопросительный знак.
Необходимо для этого слова посчитать среднее арифметическое его вхождений в предложения (без учёта регистра).
Слова в предложениях разделяются символами, для которых библиотечные функции isspace() или ispunct() возвращают
ненулевое значение.
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    double my_word = 0;
    double cnt = 0; // среднее арифметическое ь / cnt
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


