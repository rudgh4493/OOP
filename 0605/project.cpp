
#include <iostream>
#include<fstream>
using namespace std;
/*
//void ex1111() {
//
//	class Point {
//		int x, y;
//	public:
//		Point(int x = 0, int y = 0) {
//			this->x = x;
//			this->y = y;
//		}
//		friend istream& operator>>(istream& stream, Point& a);
//		friend ostream& operator<<(ostream& stream, Point a);
//	};
//
//	istream& operator >> (istream & stream, Point & a) {
//		cout << "x좌표 : ";
//		stream >> a.x;
//		cout << "y좌표 : ";
//		stream >> a.y;
//		return stream;
//	}
//	ostream& operator <<(ostream & stream, Point a) {
//		stream << "(" << a.x << "," << a.y << ")";
//		return stream;
//	}
//	int main() {
//		Point p;
//		cin >> p;
//		cout << p;
//	}
//}
void ex1201(){
	char name[10], dept[20];
	int sid;

	cout << "이름>>";
	cin >> name;
	cout << "학번(숫자로)>>";
	cin >> sid;
	cout << "학과>>";
	cin >> dept;

	ofstream fout("c:\\temp\\student.txt");
	if (!fout) {
		cout << "파일을 열수 없다";
		return 0;
	}

	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;
	fout.close();
}
void ex120203(){
	ifstream fin;
	fin.open("c:\\temp\\student.txt");
	if (!fin) {
		cout << "파일못열음";
		return 0;
	}int count = 0;
	int c;
	while ((c = fin.get()) != EOF) {
		cout << (char)c;
		count++;
	}
	cout << "읽은바이트수는" << count << endl;
	fin.close();

	/*
	char name[10], dept[20];
	int sid;

	fin >> name;
	fin >> sid;
	fin >> dept;

	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;

	fin.close();
	
}
void ex12000(){
	const char* firstFile = "c\\temp\\desert.jpg";
	const char* secondFile = "c\\temp\\copydesert.jpg";

	fstream fout(firstFile, ios::in | ios::app);
	if (!fout) {
		cout << firstFile << "열기오류";
		return 0;
	}

	fstream fin(secondFile, ios::app);
	if (!fin) {
		cout << secondFile << "열기오류";
		return 0;
	}

	char buf[81];		//한줄단위로 출력
	/*
	while (fin.getline(buf, 81)) {
		cout << buf << endl;
	}
	*/

	//위에나 이거
/*
	string line;
	while (getline(fin, line)) {
		cout << line << endl;
	}
	*/
	/*
	int c;
	while ((c = fin.get()) != EOF) {
		fout.put(c);
	}
	fin.close();
	fout.close();
	
}
*/
int main() {
	const char* firstFile = "c\\temp\\desert.jpg";
	const char* secondFile = "c\\temp\\copydesert.jpg";

	ifstream fsrc(firstFile, ios::in | ios::binary);
	if (!fsrc) {
		cout << firstFile << "열기오류";
		return 0;
	}

	ofstream fdest(secondFile, ios::out | ios::binary);
	if (!fdest) {
		cout << secondFile << "열기오류";
		return 0;
	}
	
	
	int c;
	while ((c = fsrc.get()) != EOF) {
		fdest.put(c);
	}
	cout << "복사함" << endl;
	fdest.close();
	fsrc.close();
	
}

