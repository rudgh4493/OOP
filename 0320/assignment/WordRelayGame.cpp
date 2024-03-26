#include <iostream>
#include <string>
using namespace std;

class Player {
    string name;
public:
    void setName(string n) {
        name = n; 
    }
    string getName() {
        return name;
    }
};

class WordGame {
    Player* p;
    int num;
public:
    WordGame(int n);
    void game();
};

WordGame::WordGame(int n) {
    num = n;
    p = new Player[n];
}

void WordGame::game() {
    string n;
    for (int i = 0; i < num; i++) {
        cout << "참가자의 이름을 입력하세요. 빈칸 없이>>";
        cin >> n;
        p[i].setName(n);
    }

    cout << endl;
    cout << "시작하는 단어는 아버지입니다" << endl;
    string a = "아버지";
    string b;
    int i = 0;
    while (true) {
        cout << p[i % num].getName() << ">>";
        cin >> b;
        int j = a.size();
        if (a.at(j - 2) == b.at(0) && a.at(j - 1) == b.at(1)) {
            a = b;
        }
        else {
            cout << p[i % num].getName() << "(이)가 패배하였습니다.." << endl;
            break;
        }
        i++;
    }
}

int main() {
    int num;
    cout << "끝말 잇기 게임을 시작합니다" << endl;
    cout << "게임에 참가하는 인원은 몇명입니까?";
    cin >> num;

    WordGame WordGame(num);
    WordGame.game();
}