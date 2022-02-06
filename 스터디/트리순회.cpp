// boj 1991 트리 순회
#include <cstdio>
using namespace std;

struct info{
	char now;
	char left;
	char right;
};

int n;
info tree[26];

void preorder(int num){ // 전위순회 
	printf("%c", tree[num].now);
	if(tree[num].left != '.') preorder(tree[num].left-'A');
	if(tree[num].right != '.') preorder(tree[num].right-'A');
}
void inorder(int num){ // 중위순회 
	if(tree[num].left != '.') inorder(tree[num].left-'A');
	printf("%c", tree[num].now);
	if(tree[num].right != '.') inorder(tree[num].right-'A');
} 
void postorder(int num){ // 후위순회 
	if(tree[num].left != '.') postorder(tree[num].left-'A');
	if(tree[num].right != '.') postorder(tree[num].right-'A');
	printf("%c", tree[num].now);
}

int main(){
	scanf("%d", &n);
	getchar();
	for(int i=0; i<n; i++){
		char a, b, c;
		scanf("%c %c %c", &a, &b, &c);
		getchar();
		tree[a-'A'] = {a, b, c};
	}
	
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	printf("\n");
	
	
	return 0;
} 
