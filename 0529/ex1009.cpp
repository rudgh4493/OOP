#include <vector>
#include <map>
#include <string>
#include <algorithm>

#include <iostream>
using namespace std;
void ex1009() {
	vector<int> v;		//정수 벡터 만들기
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.push_back(1);		//벡터에 정수 삽입
	v.push_back(2);
	v.push_back(3);

	vector<int>::iterator it;
	for (it = v.begin(); it != v.end(); it++) {
		int n = *it;
		n = n * 2;
		*it = n;
	}
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << ' ';
		cout << endl;
	}

}
void ex1012() {
	map<string, string>dic;

	dic.insert(make_pair("love", "사랑"));
	dic.insert(make_pair("apple", "사과"));
	dic.insert(make_pair("orange", "오렌지"));
	dic["cherry"] = "체리";

	cout << "단어 갯수 : " << dic.size() << endl;
	string eng;
	while (true) {
		cout << "찾고싶은 단어 : ";
		getline(cin, eng);
		if (eng == "exit")
			break;
		if (dic.find(eng) == dic.end())
			cout << "없음" << endl;
		else
			cout << dic[eng] << endl;
	}
}
void ex1013() {
		vector<int>v;
		cout << "5개의 정수를 입력하세요 : ";
		for (int i = 0; i < 5; i++) {
			int n;
			cin >> n;
			v.push_back(n);
		}
		sort(v.begin(), v.end());

		vector<int>::iterator it;

		for (it = v.begin(); it != v.end(); it++) {
			cout << *it << ' ';
		}
		cout << endl;


}
int main() {
	//람다식 만들기
	[](int x, int y) {cout << "합 : " << x + y; }(20, 50);
}