#ifndef _SUBS_H
#define _SUBS_H

//INSERT-LGPL-HEADER-HERE//

char *skipwhite(char *s);			// skip leading spaces and tabs
void truncate(char *s, const char *tchars);	// truncate string at specified char(s)
const char *itoa(int i);			// convert an int to an ascii string

#endif
