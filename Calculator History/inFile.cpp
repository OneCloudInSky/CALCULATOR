#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void inFile(string initExp, int result) { //���� � ���� ������������ ���������(initial expression) � ����������(result)
	ofstream  fout("Calculator History.txt");
	
	fout << initExp << ' ' << result << "\n";
	fout << "string" << 5;
}

int main() {
	inFile("sfaf", 6);
	
}


