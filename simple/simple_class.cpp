#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Student {
private:
    char *LastName;
    char *FirstName;
    int Course;
public:
    Student(char *LN, char *FN, int C){
        LastName = new char[strlen(LN)];
        strcpy(LastName, LN);
        FirstName = new char[strlen(FN)];
        strcpy(FirstName, FN);
        Course = C;
    }
    Student(const Student &S){
        cout << "COPY\n";
        LastName = new char[strlen(S.LastName)];
        strcpy(LastName, S.LastName);
        FirstName = new char[strlen(S.FirstName)];
        strcpy(FirstName, S.FirstName);
        Course = S.Course;
    }
    ~Student(){
        //delete[] LastName;
        //delete[] FirstName;
    }
    void set(char *LN, char *FN, int C){
        LastName = new char[strlen(LN)];
        strcpy(LastName, LN);
        FirstName = new char[strlen(FN)];
        strcpy(FirstName, FN);
        Course = C;
    }
    char *get(){
        char *res;
        sprintf(res, "%s, %s, %d", LastName, FirstName, Course);
        return res;
    }
    void show(){
        cout << LastName << ", " << Course <<".\n";
    }


};

int main(){
    char punct;

    Student ob2("a", "a", 0);
    ob2.set("Petrov", "Petr", 3);
    printf("%s", ob2.get());
    return 0;
}
