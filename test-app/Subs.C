#include <stdio.h>
#include <string.h>

//INSERT-LGPL-HEADER-HERE//

// Skip over leading white space; return pointer to first non-white char
char *skipwhite(char *s) {
    while ( *s == ' ' || *s == 9 ) { ++s; }
    return(s);
}

// Truncate string 's' at any matching character in 'tchars'
void truncate(char *s, const char *tchars) {
    while (*s) {
        if ( strchr(tchars, *s) ) {	// char in set?
	    *s = 0;			// truncate
	    break;
	}
	++s;
    }
}

// Convert integer to an ascii string
//     Opposite of atoi(3)
//
const char *itoa(int i) {
    static char s[80];
    sprintf(s, "%d", i);
    return(s);
}
