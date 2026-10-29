#include <stdio.h>
#include <string.h>

//INSERT-LGPL-HEADER-HERE//

// Skip leading spaces and tabs; return the first other character (or terminator).
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
