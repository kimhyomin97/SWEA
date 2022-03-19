// boj 9177 단어 섞기
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string a, b, c;
int len1,len2,len3;
bool ans;
void recur(int len, int index1, int index2){
	if(ans) return;
	if(len == len3){
		ans = true;
		return;
	}
	if(c[len]==a[index1]) recur(len+1, index1+1, index2);
	if(c[len]==b[index2]) recur(len+1, index1, index2+1);
}
bool check(){
	int alpa[26] = {0,};
	for(int i=0; i<len1; i++){
		alpa[a[i]-'a']++;
	}
	for(int i=0; i<len2; i++){
		alpa[b[i]-'a']++;
	}
	for(int i=0; i<len3; i++){
		alpa[c[i]-'a']--;
	}
	for(int i=0; i<26; i++){
		if(alpa[i]!=0) return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
//	scanf("%d", &n); // scanf쓰면 틀림 
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a >> b >> c;
		len1 = a.length();
		len2 = b.length();
		len3 = c.length();
		ans = false;
		if(check()){
			recur(0, 0, 0);
		}
//		if(ans) printf("Data set %d: yes\n", i);
//		else printf("Data set %d: no\n", i);
		if(ans) cout<<"Data set " << i << ": " << "yes\n";
		else cout<<"Data set " << i << ": " << "no\n";
	}
	return 0;
} 
