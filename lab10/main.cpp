#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
			if(pos != string::npos) {
				for(size_t i = pos + a.length() + 1; (str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z'); i++) {
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