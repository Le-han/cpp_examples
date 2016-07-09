#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <stdlib.h>

using namespace std;
namespace numbers {
    class complex{
        double real;
        double imagine;
        friend complex operator+(const complex &a1, const complex &a2);
        friend complex operator-(const complex &a1, const complex &a2);
        friend complex operator*(const complex &a1, const complex &a2);
        friend complex operator/(const complex &a1, const complex &a2);
        friend complex operator-(const complex &a1);
        friend complex operator~(const complex &a1);
    public:
        double get_re() const {return real;}
        double get_im() const {return imagine;}

        long double abs() const {return sqrtl(real * real + imagine * imagine);}
        long double abs2()const {return real * real + imagine * imagine;}

        char *to_string (char *buf, size_t size)const {
            snprintf(buf, size, "(%.10g,%.10g)", real, imagine);
            return buf;
        }
        complex(double re = 0, double im = 0){
            real = re;
            imagine = im;
        }
        explicit complex(const char *str){
            double a, b;
            sscanf(str, "(%lf, %lf", &a, &b);
            real = a;
            imagine = b;
        }
    };

    complex operator+(const complex &a1, const complex &a2){
        complex t;
        t.real = a1.real + a2.real;
        t.imagine =  a1.imagine + a2.imagine;
        return t;
    }
    complex operator-(const complex &a1, const complex &a2){
        complex t;
        t.real = a1.real - a2.real;
        t.imagine =  a1.imagine - a2.imagine;
        return t;
    }
    complex operator*(const complex &a1, const complex &a2){
        complex t;
        t.real = a1.real * a2.real - a1.imagine * a2.imagine;
        t.imagine = a1.real * a2.imagine + a1.imagine * a2.real;
        return t;
    }

    complex operator/(const complex &a1, const complex &a2){
        complex t;
        t.real = (a1.real * a2.real + a1.imagine * a2.imagine) / (a2.real * a2.real + a2.imagine * a2.imagine);
        t.imagine = (a2.real * a1.imagine - a2.imagine * a1.real) / (a2.real * a2.real + a2.imagine * a2.imagine);
        return t;
    }
    complex operator~(const complex &a){
        complex t;
        t.real = a.real;
        t.imagine = -a.imagine;
        return t;
    }

    complex operator-(const complex &a){
        complex t;
        t.real = -a.real;
        t.imagine = -a.imagine;
        return t;
    }
    //////////////////////////////
    /////////////////////////PART2
    //////////////////////////////
    class complex_stack {
private:
    complex *arr;
    int new_sz;
    int cur_sz;

    friend complex_stack operator<<(const complex_stack &t, const complex new_el);
    friend complex operator+(const complex_stack &t);
    friend complex_stack operator~(const complex_stack &t);
public:
    complex_stack():new_sz(256), cur_sz(0) {
        arr = new complex[256];
    }
    complex_stack (const complex_stack &t);
    ~complex_stack(){
        if (arr){
            delete []arr;
        }
    }

    void push(const complex new_el);
    complex pop();

    complex& operator [] (const int index) const{
        return arr[index];
    }
    complex_stack& operator=(const complex_stack& t){
        complex_stack tmp = complex_stack(t);
        std::swap(arr, tmp.arr);
        new_sz = tmp.new_sz;
        cur_sz = tmp.cur_sz;
        return *this;
    }

    size_t size() const{
        return cur_sz;
    }
};
//MY_constructor
complex_stack::complex_stack (const complex_stack &t) {
    new_sz = t.new_sz;
    cur_sz = t.cur_sz;
    arr = new complex[new_sz];
    for (int i = 0; i < cur_sz; i++) {
        arr[i] = t.arr[i];
    }
}

/////////PUSH PART
void complex_stack::push(const complex new_el){
    if (new_sz == cur_sz)
    {
        int i;
        complex_stack ob(*this);
        delete []arr;
        new_sz += new_sz; // size*2
        arr = new complex[new_sz];
        for (i = 0; i < cur_sz; ++i){
            arr[i] = ob.arr[i];
        }
    }
    arr[cur_sz] = new_el;
    ++cur_sz;
}
//push operator
complex_stack operator<<(const complex_stack &t, const complex new_el){
    complex_stack ob = complex_stack(t);
    ob.push(new_el);
    return ob;
}


///////POP PART
complex complex_stack::pop(){
    --cur_sz;
    return arr[cur_sz];
}
//pop operator
complex_stack operator~(const complex_stack &t){
    complex_stack ob = complex_stack(t);
    ob.pop();
    return ob;
}

//elem from the top
complex operator+(const complex_stack &t){
	return t.arr[t.cur_sz - 1];
}
///////////////////////////////
//////////////////////PART3
//////////////////////////////
#define ADD 1
#define SUB 2
#define MUL 3
#define DIV 4
#define ZET 5

complex eval(char **args, const complex &z)
    {
        long long index = 0;
        complex_stack st;
        complex op1, op2;
        while(args[index]) {
            switch (args[index][0])
            {
            case '(' :
                op1 = complex(args[index]);
                st = st << op1;
                break;
            case 'z' :
                st = st << z;
                break;
            case '+' :
                op2 = +st;
                st = ~st;
                op1 = +st;
                st = ~st;
                st = st << (op1 + op2);
                break;
            case '-' :
                op2 = +st;
                st = ~st;
                op1 = +st;
                st = ~st;
                st = st << (op1 - op2);
                break;
            case '*' :
                op2 = +st;
                st = ~st;
                op1 = +st;
                st = ~st;
                st = st << (op1 * op2);
                break;
            case '/' :
                op2 = +st;
                st = ~st;
                op1 = +st;
                st = ~st;
                st = st << (op1 / op2);
                break;
            case '!' :
                st = st << (+st);
                break;
            case ';' :
                st = ~st;
                break;
            case '~' :
                op1 = +st;
                st = ~st;
                op1 = ~op1;
                st = st << op1;
                break;
            case '#' :
                op1 = +st;
                st = ~st;
                op1 = -op1;
                st = st << op1;
                break;
            default : break;
            }
            index++;
        }
        return +st;
    }
}
