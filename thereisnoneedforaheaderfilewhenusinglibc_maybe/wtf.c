
int main(){
char string[64] = {'s', 't', 'd', 'i', 'o', '?', '\0'};
printf("%s\n", string);
strcat(string, "string?");
printf("%s\n", string);
}
