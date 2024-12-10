#define ALARMNUMBER 120103119
#define MACROENDCHAR 36
#define LENMAX_STR 385
#define LENMAX_DECI 129

#include <stdio.h>

int text_from_file(char* filename_strg, char* cyphcontent_strg);

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
	int ret = -1;
	int i, j;
	int num, tempn;
	char str[LENMAX_STR];
	char deci[LENMAX_DECI];
	/** 这一部分判断代码本懒狗决定先按简单的方式写，以后需要改了再改 */
	if(argc < 2){
		printf("usage:\n");
		printf("-k: use keyboard as input;\n");
		printf("-f %%filename: use file named \e[1m%%filename\e[0m as input\n");
		return 0;
	}
	if(argc == 2){
		scanf("%[^\n]",str);
	}
	if(argc == 3){
		ret = text_from_file(argv[2], str);
		if(ret < 0){
			return ret;
		}
	}
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

int text_from_file(char* filename_strg, char* cyphcontent_strg)
{
	FILE *textfile_p = fopen(filename_strg, "r");
	if(textfile_p == NULL){
		fprintf(stderr, "E:error on opening file %s.\n", filename_strg);
		return -1;
	}
	else{
		fseek(textfile_p, 0, SEEK_END);
		long textfile_size = ftell(textfile_p);
		fseek(textfile_p, 0, SEEK_SET);
		if(textfile_size > LENMAX_STR){
			fprintf(stderr, "E:too long text file.\n");
			return -2;
		}
		fread(cyphcontent_strg, 1, textfile_size, textfile_p);
		cyphcontent_strg[textfile_size] = '\0';
		fclose(textfile_p);
	}
	return 0;
}
