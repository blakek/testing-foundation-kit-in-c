#include <CoreFoundation/CoreFoundation.h>
#include <CoreFoundation/CFUserNotification.h>

#include <stdio.h>

int main(int argc, char **argv)
{
    CFTimeInterval timeout = 0;
    CFOptionFlags flags = kCFUserNotificationPlainAlertLevel | kCFUserNotificationNoDefaultButtonFlag;
    SInt32 error;

    const void *keys[] = {
        kCFUserNotificationAlertHeaderKey,
        kCFUserNotificationDefaultButtonTitleKey};

    const void *values[] = {
        CFSTR("Progress"),
        CFSTR("Cancel")};

    CFDictionaryRef parameters = CFDictionaryCreate(0,
                                                    keys,
                                                    values,
                                                    sizeof(keys) / sizeof(*keys),
                                                    &kCFTypeDictionaryKeyCallBacks,
                                                    &kCFTypeDictionaryValueCallBacks);

    CFUserNotificationRef n = CFUserNotificationCreate(
        kCFAllocatorDefault,
        timeout,
        flags,
        &error,
        NULL);

    printf("%d", n);
}
