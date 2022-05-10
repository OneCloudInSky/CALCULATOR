#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

int hCounter = 0;

void Replace(string& s, string pattern, string replacer) {
	s = regex_replace(s, regex{ pattern }, replacer);
}

int inFile(string initExp, string result) { // ���� � ���� ������������ ���������(initial expression) � ����������(result)
	ofstream  calcFile("Calculator History.txt", ios_base::app);
	
	if (!calcFile.is_open())  {
		cout << "\n   #File opening error accused!#   \n";
		return 0;
	}
	
	hCounter++;
	
	calcFile << hCounter << ". "<< initExp << ' ' << result << "\n";
	
	calcFile.close();
}

string getLast() { // ����� �� ����� ���������� �������� 
	ifstream calcFile("Calculator History.txt");
	
	if (!calcFile.is_open()) cout << "\n   #File opening error or non existing#   \n";
	
	else {
		string tmpLine, lastLine;
		
		while (calcFile) {	
			getline(calcFile, tmpLine);
			
			if (tmpLine[0] - 'a' + '1' == hCounter) {
				Replace(tmpLine, "[0-9.]+$|^[0-9]+[.]{1}[ ]{1}", "");
				lastLine = tmpLine;
				break;
			}	
		}
		
		return lastLine;
	}
}

string getInit(int needed) { //  �������, ��������� ������ ��������� �� ������ � �������!!!
	ifstream calcFile("Calculator History.txt");
	
	if (!calcFile.is_open()) cout << "\n   #File opening error or non existing#   \n";
	
	else {
		string tmpLine, neededLine;
		
		while (calcFile) {	
			getline(calcFile, tmpLine);
			
			if (tmpLine[0] - 'a' + '1' == needed) {
				Replace(tmpLine, "[0-9.]+$|^[0-9]+[.]{1}[ ]{1}", "");
				neededLine = tmpLine;
				break;
			}		
		}	
		
		return neededLine;
	}
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

void clearHistory() { //������ ������� �������
	ofstream calcFile("Calculator History.txt", ios_base::trunc);
	hCounter = 0;
}



