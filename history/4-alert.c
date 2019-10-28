#include <CoreFoundation/CoreFoundation.h>
#include <CoreFoundation/CFUserNotification.h>

#include <stdio.h>

int main(int argc, char **argv)
{
    CFTimeInterval timeout = 0;
    CFOptionFlags flags = kCFUserNotificationPlainAlertLevel | kCFUserNotificationNoDefaultButtonFlag;
    SInt32 error;
    CFOptionFlags responseFlags;

    CFStringRef title = CFStringCreateWithCString(
        kCFAllocatorDefault,
        "This is the title",
        kCFStringEncodingUTF8);

    CFStringRef message = CFStringCreateWithCString(
        kCFAllocatorDefault,
        "A message",
        kCFStringEncodingUTF8);

    CFUserNotificationDisplayAlert(
        timeout,
        kCFUserNotificationPlainAlertLevel,
        NULL,
        NULL,
        NULL,
        title,
        message,
        NULL,
        NULL,
        NULL,
        &responseFlags);

    printf("Response: %lu\n", responseFlags);
}
