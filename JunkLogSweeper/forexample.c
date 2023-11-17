/**
 * @charset utf-8
 * @file forexample.c
 * @author 被诡异逻辑的库搞到红温状态的码农
 * @brief 假如根据协议规定需要使用标准输出通信，而不得不调用的鬼库却喜欢用标准输出作为日志抢答原本回应的话
 * @attention 1. 请不要在代码中使用粗俗语言，这可能会带来精神创伤；
              2. 请不要在工作代码中使用粗俗语言，这可能会带来解雇；
			  3. 请注意对于某些嵌入式libc，`printf("string")`的行为并不等同于`fprintf(stdout, "string")`；
 * @version 0.1
 * @date 2023-11-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

#include "junklogsweeper.h"

int main(int __attribute__((unused)) argc, char __attribute__((unused)) *argv[])
{
	int i = 0; /* warn me this please */
	printf("Content-Type: text/plain\n\n");

	FILE* devnull_stream = opensomeNULL();
	FILE* original_stdout = keepstdoutclean(devnull_stream);

    fprintf(stdout, "你那个**日志输出能不能去它该去的地方？\n");
    fprintf(stdout, "would you please let your fart log go to where it should go to!\n");
	fprintf(stdout, "如果不是用幼儿识字课本学的C语言就应该知道有个东西叫标准错误输出！\n");
    fprintf(stdout, "if you didn't learn ur dummy programmig with alphabet cards for children you should know stdout isn't stderr!\n");

	nowspeak(original_stdout);

	fprintf(stdout, "hello, what a nice day, how are you today.\n");

	fclose(original_stdout);
	fclose(devnull_stream);

	return 0;
}
