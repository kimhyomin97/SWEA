// Äíµù2¹ø 
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string std;	
	vector <string> arr;
	vector <int> list;
	for(int i=0; i<7; i++) list.push_back(0);
	string names[7] = {"At", "Sa", "Ft", "Hi", "Bi", "Mv", "De"};
	// At Sa Ft Hi Bi Mv De
	vector <double> rate;
	int len = 0; 
	freopen("input.txt", "r", stdin);
	while(scanf("%s", std.c_str())){
		arr.push_back(std);
		if(std == "At") list[0]++;
		if(std == "Sa") list[1]++;
		if(std == "Ft") list[2]++;
		if(std == "Hi") list[3]++;
		if(std == "Bi") list[4]++;
		if(std == "Mv") list[5]++;
		if(std == "De") list[6]++;
		len++;
	}
//	while(cin >> std){
//		arr.push_back(std);
//		if(std == "At") list[0]++;
//		if(std == "Sa") list[1]++;
//		if(std == "Ft") list[2]++;
//		if(std == "Hi") list[3]++;
//		if(std == "Bi") list[4]++;
//		if(std == "Mv") list[5]++;
//		if(std == "De") list[6]++;
//		len++;
//	}
	for(int i=0; i<7; i++) {
		double temp = (double)list[i]/len;
		rate.push_back(temp);
		printf("%s %d %.2f\n", names[i].c_str(), list[i], rate[i]);
	}
	cout << "Total " << len << " 1.00"; 
	return 0;
}
