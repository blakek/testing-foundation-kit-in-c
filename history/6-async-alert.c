#include <CoreFoundation/CoreFoundation.h>
#include <CoreFoundation/CFNotificationCenter.h>
#include <CoreFoundation/CFUserNotification.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    CFTimeInterval timeout = 0;
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

    int ret = CFUserNotificationDisplayNotice(
        timeout,
        kCFUserNotificationStopAlertLevel,
        NULL,
        NULL,
        NULL,
        title,
        message,
        NULL);

    printf("Response: %d\n", ret);
}
