--- logrotate.c.orig
+++ logrotate.c
@@ -1,5 +1,4 @@
 #include <sys/queue.h>
-#include <alloca.h>
 #include <ctype.h>
 #include <dirent.h>
 #include <errno.h>
@@ -16,6 +15,7 @@
 #include <locale.h>
 #include <sys/types.h>
 #include <utime.h>
+#include <limits.h>
 
 #if defined(SunOS) 
 #include <syslimits.h>
