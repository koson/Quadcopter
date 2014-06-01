#include "quad_tasks.hpp"

#include "FreeRTOS.h"
#include "semphr.h"



/// Define the stack size this task is estimated to use
#define GPS_TASK_STACK_BYTES        (3 * 512)



gps_task::gps_task(UartDev *pGpsUart, const uint8_t priority) :
    scheduler_task("gps", GPS_TASK_STACK_BYTES, priority),
    mpGpsUart(pGpsUart)
{
    /* Use init() for memory allocation */
}

bool gps_task::init(void)
{
    bool success = true;

    if (success) {
        /* Init something here */
    }

    // Do not update task statistics (stack usage) too frequently
    setStatUpdateRate(5 * 60 * 1000);

    return success;
}

bool gps_task::run(void *p)
{
    const uint32_t gpsTimeoutMs = 1100;
    char buffer[256] = { 0 };

    /* Log an error if GPS data not retrieved within the expected time */
    if (!mpGpsUart->gets(&buffer[0], sizeof(buffer), OS_MS(gpsTimeoutMs))) {
        /* ... */
    }
    else {
        /* Parse the GPS string */

        /* Set the GPS data on the Quadcopter class */
    }

    return true;
}
