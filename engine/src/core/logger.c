#include "logger.h"
#include "defines.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void report_assertion_failure(const char *expression, const char *message,
                              const char *file, int line) {
  log_output(LOG_LEVEL_FATAL,
             "Assertion Failure: %s, message: '%s', file: '%s', line: %d\n",
             expression, message, file, line);
}

bool init_logging() { /* create log file */
  return true;
}

void shutdown_logging() { /* write to file */
}

void log_output(log_level level, const char *message, ...) {

  // different to the kohi engine
  // for bugs revisit video #003

  const char *log_level_prefix[6] = {"[FATAL]", "[ERROR]", "[WARN]",
                                     "[INFO]",  "[DEBUG]", "[TRACE]"};

  char message_buffer[32000];
  memset(message_buffer, 0, sizeof(message_buffer));

  // va_list of GCC/CLANG
  __builtin_va_list arg_ptr;
  va_start(arg_ptr, message);
  vsnprintf(message_buffer, 32000, message, arg_ptr);
  va_end(arg_ptr);

  printf("%s %s\n", log_level_prefix[level], message_buffer);
}
