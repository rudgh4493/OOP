#include <vector>
#include <map>
#include <string>
#include <algorithm>

#include <iostream>
using namespace std;
void ex1009() {
	vector<int> v;		//���� ���� �����
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.push_back(1);		//���Ϳ� ���� ����
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

	dic.insert(make_pair("love", "���"));
	dic.insert(make_pair("apple", "���"));
	dic.insert(make_pair("orange", "������"));
	dic["cherry"] = "ü��";

	cout << "�ܾ� ���� : " << dic.size() << endl;
	string eng;
	while (true) {
		cout << "ã����� �ܾ� : ";
		getline(cin, eng);
		if (eng == "exit")
			break;
		if (dic.find(eng) == dic.end())
			cout << "����" << endl;
		else
			cout << dic[eng] << endl;
	}
}
void ex1013() {
		vector<int>v;
		cout << "5���� ������ �Է��ϼ��� : ";
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
	//���ٽ� �����
	[](int x, int y) {cout << "�� : " << x + y; }(20, 50);
}