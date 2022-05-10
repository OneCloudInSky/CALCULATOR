#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int hCounter = 0;

int inFile(string initExp, string result) { // ���� � ���� ������������ ���������(initial expression) � ����������(result)
	ofstream  calcFile("Calculator History.txt", ios_base::app);
	
	if (!calcFile.is_open())  {
		cout << "\nFile opening error accused!\n";
		return 0;
	}
	
	hCounter++;
	
	calcFile << hCounter << ". "<< initExp << ' ' << result << "\n";
	
	calcFile.close();
}

void seeLast() { // ����� �� ����� ���������� �������� 
	
}

string getInit() { //  �������, ��������� ������ ��������� �� ������ � �������!!!
	//
}

void seeHistory() { // ����� �� ����� ���� �������
	ifstream calcFile("Calculator History.txt");
	
	if (!calcFile.is_open()) cout << "\n   #The history was cleaned or non existing#   \n";
	
	else {
		while (calcFile) {
			string line;
			
			getline(calcFile, line);
			
			if (line == "") break;
			else cout << line << "\n";
		}
		
		calcFile.close();
	}
}

int createFile() { // ������� ��������������� �������� �����(�������������)
	ofstream calcFile("Calculator History.txt");
	calcFile.close();
}

void clearFile() { //������ ������� �������
	ofstream calcFile("Calculator History.txt", ios_base::trunc);
}



int main() { // �������� ������� ��� ������������
	return 0;
}


