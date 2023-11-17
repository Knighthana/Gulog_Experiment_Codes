/**
 *
 * @charset utf-8
 * @author Knighthana
 * suggest reading with a monospace kind of font
 * @brief definition for redirection and re-redirection function
 *
*/

#include "junklogsweeper.h"

#ifdef _USESTREAMMETHOD_

/**
 * the first func to call
 * @brief create a FILE struct which points to `/dev/null`
 * @param  void nothing needed to pass in
 * @return the FILE struct pointer which points to `dev/null`, which will be useful latter
 */
FILE* opensomeNULL(void)
{
	FILE* devnull = fopen("/dev/null", "w");
	if(devnull == NULL){
		perror("failed to open /dev/null");
		return NULL;
	}
	return devnull;
}

/**
 * the first func (as another option) to call
 * @brief rather than dropping the file, you are insterested in turning that junk into a file
 * @param filepathname a char* string described full-path-name of a file,
 *                     which you think the libc might accept as a filename string
 * @return the FILE struct pointer which points to the file located at `filepathname`, which will be useful later
 */
FILE* openredirectlogfile(char* filepathname)
{
    FILE* fp = fopen(filepathname, "w");
    if(fp == NULL){
        perror("failed to open specified log recording file");
        return NULL;
    }
    return fp;
}

/**
 * use before the junk-maker, the second func to call under most situations
 * @brief start to make all the output into somewhere you wish it goes to, for example, `/dev/null`
 * @param blackhole the FILE struct pointer
 *                  which you recently made
 *                  with func `opensomeNULL(blahblah)` or `openredirectlogfile(blahblah)`
 * @return the original `stdout`
 *         which we can get in the process. 
 *         be aware that if their is no valid `stdout` at the begining, this func made **NOTHING HELPFUL** for that
 */
FILE* keepstdoutclean(FILE* blackhole)
{
	FILE* original = stdout;
	if(original == NULL){
		perror("failed to save original stdout stream");
		return NULL;
	}

	stdout = blackhole;
	
	return original;
}

/**
 * @brief 
 * @param orgsot 
 */
void nowspeak(FILE* orgsot)
{
	fflush(stdout);
	stdout = orgsot;
	return;
}

#elif defined _USESYSCALLMETHOD_

/**
 * use this function firstly
 * @brief to open a file descriptor of `/dev/null`
 * 
 * @return int file descriptor of `/dev/null`
 */
int opensomeNULL(void)
{
    int devnull_fd = open("/dev/null", O_WRONLY);
    if(devnull_fd == -1){
        perror("failed to open /dev/null");
        return -1;
    }
    return devnull_fd;
}

/**
 * use this function secondly
 * @brief to open the original file descriptor,
 *        and replace the original file descriptor
 *        with input argument
 * @param devnull_fd the place where you want the junk goes to
 * @return the original file descriptor 
 * @attention keep return value saved in any int varible, 
 *            unless you want to lose your standard output
 */
int __attribute__((warn_unused_result)) keepstdoutclean(int devnull_fd)
{
    int original = dup(STDOUT_FILENO);
    if(original == -1){
        perror("failed to save original stdout fd");
        return -2;
    }

    if(dup2(devnull_fd, STDOUT_FILENO) == -1){
        perror("failed to redirect stdout");
        return -3;
    }

    return original;
}

/**
 * @brief use this function at last
 * 
 * @param orgsot the original standard output file descriptor
 * @return 0 if succeed, other value if met failure
 */
int nowspeak(int orgsot)
{
    if(dup2(orgsot, STDOUT_FILENO) == -1){
        perror("failed to restore stdout");
        return -4;
    }
    return 0;
}

#endif
