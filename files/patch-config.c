--- config.c.orig
+++ config.c
@@ -1,5 +1,4 @@
 #include <sys/queue.h>
-#include <alloca.h>
 #include <ctype.h>
 #include <dirent.h>
 #include <errno.h>
@@ -19,6 +18,7 @@
 #include <wctype.h>
 #include <fnmatch.h>
 #include <sys/mman.h>
+#include <limits.h>
 
 #include "basenames.h"
 #include "log.h"
@@ -100,7 +100,7 @@ static char *readPath(const char *configFile, int lineNum, char *key,
 
 	chptr = start;
 
-	while( (len = mbrtowc(&pwc, chptr, strlen(chptr), NULL)) != 0 ) {
+	while( (len = strlen(chptr)) != 0 && (len = mbrtowc(&pwc, chptr, len, NULL)) != 0 ) {
 		if( len == (size_t)(-1) || len == (size_t)(-2) || !iswprint(pwc) || iswblank(pwc) ) {
 		    message(MESS_ERROR, "%s:%d bad %s path %s\n",
 			    configFile, lineNum, key, start);
