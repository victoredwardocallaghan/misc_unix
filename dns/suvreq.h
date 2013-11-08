#ifndef _SUVREQ_H_
#define _SUVREQ_H_
/*[suvreq-h]*/
/*
    Header to request specific standard support. Before including it, one
    of the following symbols must be defined (1003.1-1988 isn't supported):

        SUV_POSIX1990   for 1003.1-1990
        SUV_POSIX1993   for 1003.1b-1993 - real-time
        SUV_POSIX1996   for 1003.1-1996
        SUV_SUS1        for Single UNIX Specification, v. 1 (UNIX 95)
        SUV_SUS2        for Single UNIX Specification, v. 2 (UNIX 98)
        SUV_SUS3        for Single UNIX Specification, v. 3
*/

#ifdef _POSIX_SOURCE /* tmp */
#error
#endif

#if defined(SUV_POSIX1990)
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 1

#elif defined(SUV_POSIX1993)
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

#elif defined(SUV_POSIX1996)
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199506L

#elif defined(SUV_SUS1)
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 2
#define _XOPEN_SOURCE
#define _XOPEN_SOURCE_EXTENDED 1

#elif defined(SUV_SUS2)
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199506L
#define _XOPEN_SOURCE 500
#define _XOPEN_SOURCE_EXTENDED 1

#elif defined(SUV_SUS3)
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 200112L
#define _XOPEN_SOURCE 600
#define _XOPEN_SOURCE_EXTENDED 1
#endif
/*[]*/

#endif /* _SUVREQ_H_ */
