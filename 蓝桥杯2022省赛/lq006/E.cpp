#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
 
using namespace std;
 
const int maxn = 1000001;
 
 
char text[maxn];
char pattern[maxn];
int nnext[maxn];
 

void get_next() {
	int patternLen = strlen(pattern);
 
	nnext[0] = nnext[1] = 0;
	for (int i = 1; i < patternLen; i++) {
		int j = nnext[i];
		while (j && pattern[i] != pattern[j]){
			j = nnext[j];
		}
		nnext[i + 1] = pattern[i] == pattern[j] ? j + 1 : 0;
	}
}
 

int kmp() {
 
	int ans = 0;
 
	int textLen = strlen(text);
	int patternLen = strlen(pattern);
 
	int j = 0;
	for (int i = 0; i < textLen; i++) {
		while (j && pattern[j] != text[i]){
			j = nnext[j];
		}
		if (pattern[j] == text[i]){
			j++;
		}
		if (j == patternLen) {
			ans++;
		}
	}
 
	return ans;
}
 
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s", pattern, text);
		get_next();
		printf("%d\n", kmp());
	}
 
	return 0;
}