#include <bits/stdc++.h>

using namespace std;

double str_to_double(string s){
    double num = 0, len = s.length(), exp = 10;
    bool point = false, neg_sign = false;
    if(s[0] == '-') {//To Handle Nagative Number
        s[0] = '0';
        neg_sign = true;
    }
    for(int i = 0; i < len; i++) {
        if(s[i] == '.') {
            point = true;
            continue;
        }
        if(point) {
            num = num + (s[i] - '0') / exp;
            exp *= 10;
        }
        else num = num * 10 + (s[i] - '0');
    }
    if(neg_sign) num = -num;
    return num;
}

bool isOperator(string str) {
    if(str == "+") return true;
    if(str == "-") return true;
    if(str == "/") return true;
    if(str == "*") return true;
    if(str == "^") return true;
    return false;
}
double operation(double v1, double v2, string oprtr) {
    if(oprtr == "+") return v1 + v2;
    if(oprtr == "-") return v1 - v2;
    if(oprtr == "*") return v1 * v2;
    if(oprtr == "/") return v1 / v2;
    if(oprtr == "^") {
        double v = 1;
        while(v2--) v *= v1;
        return v;
    }
}

double evaluatePostfix(string exprsn) {
    stack<double> stk;
    int len = exprsn.length();
    string element;
    double value;

    for(int i = 0; i < len; i++) { //scan expression
        if(exprsn[i] == ' ') {
            if(isOperator(element)) {
                double a = stk.top();
                stk.pop();
                double b = stk.top();
                stk.pop();
                double res = operation(b, a, element);
                stk.push(res);
            }
            else stk.push(str_to_double(element));
             element = "";//clear current data from element variable
        }
        else element.push_back(exprsn[i]);
    }

    return stk.top();
}

int main() {

/*
    valid postfix expression:
    1. every element (operator, operand) separted by the space.
    2. pleas a keep a space the end of expression.
    3. example: "a b + ".
*/
    string str = "3 3 ^ ";

    cout<<evaluatePostfix(str)<<endl;
    cout<<evaluatePostfix("5 3 + 8 2 - * ")<<endl;

    return 0;
}