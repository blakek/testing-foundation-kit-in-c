#include <CoreFoundation/CoreFoundation.h>
#include <CoreFoundation/CFUserNotification.h>

#include <stdio.h>

int main(int argc, char **argv)
{
    CFTimeInterval timeout = 0;
    SInt32 error;
    CFOptionFlags responseFlags;

    CFUserNotificationRef notification = CFUserNotificationCreate(
        kCFAllocatorDefault,
        timeout,
        kCFUserNotificationPlainAlertLevel,
        &error,
        NULL);

    puts("Waiting on notification");

    SInt32 response = CFUserNotificationReceiveResponse(
        notification,
        timeout,
        &responseFlags);

    printf(
        "responseFlags: %lu  response:%d  Error: %d\n",
        responseFlags,
        response,
        error);
}
