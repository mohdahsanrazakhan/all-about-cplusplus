#include<bits/stdc++.h>
using namespace std;

int findAutoCount(char *n) {
	int valueCount[10]={0},freq[10]={0};
	int count=0;
	
	for(int i=0;n[i]!='\0';i++) {
		valueCount[n[i]-'0']++;
	}
		
	for(int i=0;i<10;i++) {
		if(valueCount[i]>0)
			count++;
	}
			
	for(int i=0;n[i]!='\0';i++) {
		valueCount[i]=valueCount[i]-(n[i]-'0');
	}
		
	for(int i=0;i<10;i++)
	{
		if(valueCount[i]!=0)
			return 0;
	}
	return count;
}

int main()
{
	char str[11];
	scanf("%s",str);
	cout << findAutoCount(str);
}
