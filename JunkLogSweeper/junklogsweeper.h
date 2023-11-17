/**
 * suggest reading with a monospace kind of font
 * @encoding UTF-8
 * @author Knighthana
*/

#ifndef _JUNKLOGSWEEPER_H_
#define _JUNKLOGSWEEPER_H_

/**
 * you can choose to use stream method or use syscall method
 * by defining MACRO,
 * use _USESTREAMMETHOD_ or _USESYSCALLMETHOD_ if you like,
 * or just change the MACRO name string to avoid name conflict
 */

#define _USESTREAMMETHOD_

/*
 * this lib use stream as default
 * but the syscall and filedescriptor method also supported
 * just delete the stream-related define MACRO
 * then add this
#define _USESYSCALLMETHOD_
 * to header
*/

#ifdef _USESTREAMMETHOD_

#include <stdio.h>
#include <error.h>

/**
 * the first func (as an option) to call
 * @brief create a FILE struct which points to `/dev/null`
 * @param  void nothing needed to pass in
 * @return the FILE struct pointer which points to `dev/null`, which will be useful later
 */
FILE* opensomeNULL(void);

/**
 * the first func (as another option) to call
 * @brief if rather than dropping the file, you are insterested in turning that junk into a file
 *        always remember to fclose() this FILE* after using
 * @param filepathname a char* string described full-path-name of a file,
 *                     which you think the libc might accept as a filename string
 * @return the FILE struct pointer which points to the file located at `filepathname`, which will be useful later
 */
FILE* openredirectlogfile(char* filepathname);

/**
 * use before the junk-maker running, the second func to call under most situations
 * @brief start to make all the output into somewhere you wish it goes to, for example, `/dev/null`
 * @param blackhole the FILE struct pointer
 *                  which you recently made
 *                  with func `opensomeNULL(blahblah)` or `openredirectlogfile(blahblah)`
 * @return the original `stdout` which we can get in the process. 
 *         be aware that if their isn't any valid `stdout` at the begining, this func will make **NOTHING HELPFUL** for that.
 *         it will be useful later, so remember to store.
 */
FILE* keepstdoutclean(FILE* devnull_filestr);

/**
 * use when you finally decide to output your neccessary standard output
 * @brief start to output really meaningful content
 * @param original_stdot the FILE struct pointer that `keepstdoutclean(blahblah)` returned recently
 */
void nowspeak(FILE* original_stdot);

#elif defined _USESYSCALLMETHOD_

#include <fcntl.h>
#include <unistd.h>

int opensomeNULL(void);

int __attribute__((warn_unused_result)) keepstdoutclean(int devnull_fd);

int nowspeak(int orgsot);

#endif

#endif
