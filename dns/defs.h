#ifndef _DEFS_H_
#define _DEFS_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _POSIX_SOURCE /* tmp */
#error
#endif

#if defined(FREEBSD) || defined(DARWIN)
#define BSD_DERIVED
#endif

#if !defined(BSD_DERIVED) /* _POST_SOURCE too restrictive */
#define SUV_SUS2
#include "suvreq.h"
#endif

#ifdef __GNUC__
#define _GNU_SOURCE /* bring GNU as close to C99 as possible */
#endif

#include <unistd.h>

#ifndef _cplusplus
#include <stdbool.h> /* C99 only */
#endif
#include <sys/types.h>
#include <time.h>
#include <limits.h>
#ifdef SOLARIS
#define _VA_LIST /* can't define it in stdio.h */
#endif
#include <stdio.h>
#ifdef SOLARIS
#undef __VA_LIST
#endif
#include <stdarg.h> /* this is the place to define _VA_LIST */
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <assert.h>
#include "ec.h"

#include "logf.h"
#include "options.h"
#include "macrostr.h"
#include "extio.h"

/*
    File-permission-bit symbols
*/
/*[defs-perm]*/
#define PERM_DIRECTORY  S_IRWXU
#define PERM_FILE       (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
/*[]*/

bool setblock(int fd, bool on); /* also in c4/setblock.h */
#define syserrmsg(buf, buf_max, msg, s_errno)\
  syserrmsgtype(buf, buf_max, msg, s_errno, EC_ERRNO)
char *syserrmsgtype(char *buf, size_t buf_max, const char *msg,
  int s_errno, EC_ERRTYPE type);
char *syserrmsgline(char *buf, size_t buf_max,
  int s_errno, EC_ERRTYPE type);
const char *getdate_strerror(int e);
const char *errsymbol(int errno_arg);
void syserr(const char *msg);
void syserr_print(const char *msg);
void timestart(void);
void timestop(char *msg);

unsigned long getblksize(const char *path); /* c2/getvlksize.c */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _DEFS_H_ */
