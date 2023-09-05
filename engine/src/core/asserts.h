#pragma once

#include "defines.h"

#define GE_ASSERTIONS_ENABLED

#ifdef GE_ASSERTIONS_ENABLED


// could be deleted later if debugger is not used
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

GE_API void report_assertion_failure(const char *expression, const char *message,
                              const char *file, int line);

#define GE_ASSERT(expr, message)                                               \
  {                                                                            \
    if (expr) {                                                                \
    } else {                                                                   \
      report_assertion_failure(#expr, message, __FILE__, __LINE__);            \
      debugBreak();                                                            \
    }                                                                          \
  }

#ifdef _DEBUG
#define GE_ASSERT_DEBUG(expr, message)                                         \
  {                                                                            \
    if (expr) {                                                                \
    } else {                                                                   \
      report_assertion_failure(#expr, message, __FILE__, __LINE__);            \
      debugBreak();                                                            \
    }                                                                          \
  }
#else
#define GE_ASSERT_DEBUG(expr, message)
#endif

#else

#define GE_ASSERT(expr, message)
#define GE_ASSERT_DEBUG(expr, message)

#endif
