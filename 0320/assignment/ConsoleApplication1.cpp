﻿
#include <iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cout << "덧셈 문자열을 입력하세요" << endl;
    getline(cin, s, '\n');
    int sum = 0;
    int startIndex = 0;
    while (true) {
        int fIndex = s.find('+', startIndex);
        if (fIndex == -1) {
            string part = s.substr(startIndex);
            if (part == "") break;
            cout << part << endl;
            sum += stoi(part);
            break;
        }
        int count = fIndex - startIndex;
        string part = s.substr(startIndex, count);

        cout << part << endl;
        sum += stoi(part);
        startIndex = fIndex + 1;
    }
    cout << "다음 식의 값은 " << sum;
}
