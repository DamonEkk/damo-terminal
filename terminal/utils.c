#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

#define MAX_LENGTH PATH_MAX

// Get USER for terminal input area.
char* get_user_string(){
	char* user = getenv("USER");
	return user;
}

char* get_cd(){
	static char shortend_cd[MAX_LENGTH];
	static char cd[MAX_LENGTH];
	char* home = getenv("HOME");

	// Gets the current directory, if the directory branches from /HOME/ it will shortend the directory. Eventually will be changed when we store a current directory.
	if (getcwd(cd, sizeof(cd)) != NULL){
		if (home && strncmp(cd, home, strlen(home)) == 0) {
            		snprintf(shortend_cd, sizeof(shortend_cd), "~%s", cd + strlen(home));
			return shortend_cd;
		}
		else{
			return cd;
		}
	}
	else{
		return "Invalid";
	}
}
