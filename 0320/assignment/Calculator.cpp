#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "덧셈, 뺄셈 문자열을 입력하세요" << endl;
    getline(cin, s, '\n');

    int sum = 0;
    int startIndex = 0;
    bool isPositive = true;

    while (true) {
        int fIndex = s.find_first_of("+-", startIndex);
        if (fIndex == -1) {
            string part = s.substr(startIndex);
            if (part == "") break;
            if (isPositive)
                sum += stoi(part);
            else
                sum -= stoi(part);
            break;
        }
        int count = fIndex - startIndex;
        string part = s.substr(startIndex, count);

        if (isPositive)
            sum += stoi(part);
        else
            sum -= stoi(part);

        if (s[fIndex] == '-')
            isPositive = false;
        else if (s[fIndex] == '+')
            isPositive = true;

        startIndex = fIndex + 1;
    }
    cout << "식의 답은? : " << sum;
}