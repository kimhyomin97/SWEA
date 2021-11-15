#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector <string> split(string str, char delimiter);

int main(){
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	vector <string> res[8];
	for(int i=0; i<8; i++){
		getline(cin, str);
		res[i] = split(str, ',');
	}
//	vector <string> res[100];
//	int len=0;
//	while(getline(cin, str)){
//		res[len++] = split(str, ',');
////		cout << str << endl;
//	}

	for(int i=0; i<res[0].size(); i++){
		if(res[0][i] == "A") cout << ",김A";
		if(res[0][i] == "B") cout << ",이B";
		if(res[0][i] == "C") cout << ",김C";
		if(res[0][i] == "D") cout << ",박D";
		if(res[0][i] == "E") cout << ",하E";
	}
	cout<<endl;
	int arr[4][5] = {0, };
	int cnt = 0;
	for(int i=1; i<8; i++){
		if(res[i][0] != ""){
			cnt++;
		}
		for(int j=1; j<res[i].size(); j++){
			if(res[i][j] == "아메리카노") arr[cnt][j-1] += 2000;
			if(res[i][j] == "아아") arr[cnt][j-1] += 2500;
			if(res[i][j] == "아바라") arr[cnt][j-1] += 4000;
			if(res[i][j] == "딸기 에이드") arr[cnt][j-1] += 4500;
			if(res[i][j] == "청포도 에이드") arr[cnt][j-1] += 4500;
			if(res[i][j] == "레몬 에이드") arr[cnt][j-1] += 4500;
		}
	}
	cnt = 1;
//	string s1 = "년 ";
//	string s2 = "월 ";
//	string s3 = "일";
//	cout << s1.length() << endl;
	for(int i=1; i<8; i++){
		if(res[i][0] != ""){
			res[i][0].replace(res[i][0].find("년 "), 3, "-");
			res[i][0].replace(res[i][0].find("월 "), 3, "-");
			res[i][0].replace(res[i][0].find("일"), 3, "");
			cout << res[i][0];
			for(int j=0; j<res[0].size()-1; j++){
				cout << "," << arr[cnt][j];
			}
			if(cnt==3) break;
			cout << endl;
			cnt++;
		}
	}
	return 0;
}

vector <string> split(string input, char delimiter){
	vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}
