#ifndef __UTILS_H__
#define __UTILS_H__

typedef char *va_list;
#define _INTSIZEOF(n) ((sizeof(n)+sizeof(int)-1)&~(sizeof(int)-1))
#define va_start(ap, v)    ( ap = (va_list)&v + _INTSIZEOF(v))
#define va_arg(ap, t)  (*(t*)((ap+=_INTSIZEOF(t)) - _INTSIZEOF(t)))
#define va_end(ap)    ( ap = (va_list)0 )

void printk(const char *fmt, ...);

#endif