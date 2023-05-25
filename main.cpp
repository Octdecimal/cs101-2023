#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class ReplaceMyString {
	ifstream in;
	ofstream out;
	public:
	    void replaceString(string a, string b) {
			in.open("main.cpp");
			out.open("rmain.cpp");
			string str;
			while(!in.eof()) {
				in >> str;
			}
			str.replace(str.find(a), a.length(), b);
			out << str;
		}
};

int main() {
	ReplaceMyString my;
	my.replaceString("IU", "IU is best");
	return 0;
}