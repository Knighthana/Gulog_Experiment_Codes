#include <stdio.h>

int main(int argc, char* argv[])
{
	char str[128];
	int leng;
	scanf("%[^\36]",str);
	for(leng=0; str[leng]!=36; leng++);
	leng--;
	for( ; leng>=0; leng--){
		printf("%c", str[leng]);
	}
	return 0;
}
