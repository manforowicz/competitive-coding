#include <bits/stdc++.h>
using namespace std;

int numOfChar(char c) {
	return (c - 97);
}

string charOfNum = "abcdefghijklmnopqr"; //18 letters

int main() {
	ios::sync_with_stdio(0);
	freopen("in.in", "r", stdin);
	string s1; cin >> s1;
	string s2; cin >> s2;
	
	int disconnected [18][18] = {0}; //demarcates breaks between letter 1 and 2.
	
	
	for (int charNum=0; charNum<18; charNum++) {
		int i1 = 0;
		int i2 = 0;
		int s1Occurences = 0;
		int s2Occurences = 0;
		while (i1 < (int) s1.length() and i2 < (int) s2.length()) {
			int count1[18] = {0};
			int count2[18] = {0};
			
			
			while (numOfChar(s1[i1]) != charNum and i1 < (int) s1.length()) {
				count1[numOfChar(s1[i1])]++;
				i1++;
			}
			if (numOfChar(s1[i1]) == charNum) s1Occurences++;
			i1++;
			
			while (numOfChar(s2[i2]) != charNum and i2 < (int) s2.length()) {
				count2[numOfChar(s2[i2])]++;
				i2++;
			}
			if (numOfChar(s2[i2]) == charNum) s2Occurences++;
			i2++;
			
			//cout << charNum << ": " << s1Occurences << " " << s2Occurences << endl;
			if (s1Occurences != s2Occurences) {
				for (int checkChar=0; checkChar<18; checkChar++) {
					disconnected[charNum][checkChar] = true;
					disconnected[checkChar][charNum] = true;
				}
			} else {
			
				for (int checkChar=0; checkChar<18; checkChar++) {
					if (count1[checkChar] != count2[checkChar]) {
						disconnected[charNum][checkChar] = true;
					    //
					}  //
				}     //pyramid
			}        //of
		}           //doom
	}              //here
	              //
	
	
	//----PRINT LINKS----
	cout << "  a b c d e f g h i j k l m n o p q r";
	for (int i=0; i<18; i++) {
		cout << endl << charOfNum[i] << " ";
		for (int j=0; j<18; j++) {
			cout << disconnected[i][j] << " ";
		}
	}
	cout << endl << endl;
	//-------------------
	
	
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		string query; cin >> query;
		string answer = "Y";
		
		for (int charAI=0; charAI<(int)query.length(); charAI++) {
			for (int charBI=0; charBI<(int)query.length(); charBI++) {
				int a = numOfChar(query[charAI]);
				int b = numOfChar(query[charBI]);
				
				if (disconnected[a][b] or disconnected[b][a]) {
					answer = "N";
				}
			}
			
		}
		cout << answer;
	}
			
		
	
	return 0;
}
	
