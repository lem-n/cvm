#include "putils.h"

int strcicmp(const char* str_a, const char* str_b) {
    for (;; str_a++, str_b++) {
        int dig = tolower((unsigned char)*str_a) - tolower((unsigned char)*str_b);
        if (dig != 0 || !(*str_a))
            return dig;
    }
}

void strwsrm(char* str) {
    const char* p = str;
    do {
        while (isspace(*p)) ++p;
    } while ((*str++ = *p++));
}
