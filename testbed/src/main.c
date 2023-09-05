#include <core/asserts.h>
#include <core/logger.h>

int main(void) {
    log_output(0, "log level 0 %d %f", 12, 3.8f);
    log_output(1, "log level 0", "v1", "v2");
    log_output(2, "log level 0", "v1", "v2");
    log_output(3, "log level 0", "v1", "v2");
    log_output(4, "log level 0", "v1", "v2");

    GE_ASSERT(LOG_LEVEL_FATAL == 0, "this is a test");
    GE_ASSERT_DEBUG(LOG_LEVEL_FATAL == 1, "also a test");

    return 0;
}
