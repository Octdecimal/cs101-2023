#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class myString {
		string m_str;
	public:
		myString(string s) {
			m_str = s;
		}
};

class ReadClass{
		string a = "class";
		ifstream in;
	public:
		void showClass() {
			string str;
			in.open("main.cpp");
			while(getline(in, str)){
				string out;
				size_t pos = str.find(a);
				if(pos != string::npos && pos == 0) {
					for(size_t i = pos + a.length() + 1; (str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z')||(str[i]>='0' && str[i]<='9'||str[i]=='_'); i++) {
						out += str[i]; 
					}
				}
				if(!out.empty()){
					cout << "class " << out << "\n";
				}
			}
			in.close();
		}
};

int main() {
	ReadClass file;
	file.showClass();
	return 0;
}