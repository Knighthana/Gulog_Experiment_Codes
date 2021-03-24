#define ALARMNUMBER 120103119
#define MACROENDCHAR 36

#include <stdio.h>

int isHexNum(char input)
{
	if(((input>='0')&&(input<='9')) || ((input>='A')&&(input<='F')) || ((input>='a')&&(input<='f'))){
		return 1;
	}
	else{
		return 0;
	}
}

int char2num(char input)
{
	int out = ALARMNUMBER;
	if(input>='0' && input<='9'){
		out = input - '0';
	}
	if(input>='A' && input<='F'){
		out = input - 'A'+10;
	}
	if(input>='a' && input<='f'){
		out = input - 'a'+10;
	}
	return out;
}

int main(int argc, char* argv[])
{
	int i, j;
	int num, tempn;
	char str[385];
	char deci[128];
	scanf("%[^\n]",str);
	for(i=0; isHexNum(str[i]); i+=3){
		num = 0;
		tempn = 0;
		j = i;
		tempn = char2num(str[j]);
		/* printf("\e[32m%d\e[0m ", tempn); */
		tempn = tempn << 4;
		/* printf("\e[33m%d\e[0m ", tempn); */
		num += tempn;
		j = i + 1;
		tempn = char2num(str[j]);
		num += tempn;
		/* printf("\e[34m%d\e[0m ",num); */
		deci[i/3] = num;
	}
	deci[i/3]='\0';
	printf("%s", deci);
	printf("%c", MACROENDCHAR);
	return 0;
}
