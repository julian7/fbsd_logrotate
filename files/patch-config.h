--- config.h.orig
+++ config.h
@@ -16,6 +16,13 @@
 #define STATEFILE "/var/log/logrotate.status"
 #endif
 
+#ifdef __FreeBSD__
+    #define DEFAULT_MAIL_COMMAND "/usr/bin/mailx -s"
+    #define COMPRESS_COMMAND "/usr/bin/gzip"
+    #define UNCOMPRESS_COMMAND "/usr/bin/gunzip"
+    #define STATEFILE "/var/run/logrotate.status"
+#endif
+
 /*
  * Default settings for Linux - leave these last.
  */
