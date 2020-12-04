#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

//precondition: Input consists of two lines with the size of the password, 3 ≤ N ≤ 30,
//			followed by the text representing the encoded message whose size is
//			less than 5 mega bytes. the input text only includes lower - case alphabet letters
//postcondigion : As output your program should print the password string.

int main()
{
	//입력받은 txt 정리 
	string str1, str2, splstr;
	getline(cin, str1);
	getline(cin, str2);

	int a = 1;

	//스트링으로 받은거 int로 형변환
	stringstream ss(str1);
	int n;
	ss >> n;

	unordered_map<string, int> wordFreq;
	for (int i = 0; i < (str2.size() - n + 1); i++) {
		splstr = str2.substr(i, n);
		wordFreq[splstr]++;
	}

	unordered_map<string, int>::iterator p;
	for (p = wordFreq.begin(); p != wordFreq.end(); p++) {
		//cout << p->first << ", " << p->second << endl;
		if (p->second > a) {
			a = p->second;
		}
	}

	unordered_map<string, int>::iterator p1;
	for (p1 = wordFreq.begin(); p1 != wordFreq.end(); p1++) {
		if (p1->second == a) {
			cout << p1->first << endl;
		}
	}

	return 0;
}
