#include <iostream>
#include <fstream>
using namespace std;
int main() {
	ofstream fout;
	int a = 13;
	int b = 4;
	int c = a^b;
	fout.open("D:\\debugLogs\\pss.log", ios::app);
	if (fout.is_open())
	{
		fout << c << endl;
		fout.close();
	}
	cin.get();
}