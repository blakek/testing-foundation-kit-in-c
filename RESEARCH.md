# Cross Platform Notifications - Research

## Trying to Copy

Trying to do this:

https://github.com/julienXX/terminal-notifier/blob/master/Terminal%20Notifier/AppDelegate.m#L267

## Foundation in C

It looks like what I need is found in the [Objective-C Runtime
docs](https://developer.apple.com/documentation/objectivec/objective-c_runtime?language=objc).

Also seems useful:

- https://developer.mozilla.org/en-US/docs/Mozilla/js-ctypes/Examples/Using_Objective-C_from_js-ctypes
- https://github.com/dschep/ntfy/blob/master/ntfy/backends/darwin.py

### [`NSUserNotificationCenter`](https://developer.apple.com/documentation/foundation/nsusernotificationcenter?language=objc)

Here are the class methods found:

- `init`
- `_setAppDelegate:connect:`
- `_registerForRemotePushNotificationTypes:`
- `_unRegisterForRemotePushNotifications`
- `_setDeliveredNotifications:`
- `_removeAllDisplayedNotifications`
- `removeAllDeliveredNotifications`
- `removeScheduledNotification:`
- `_removePresentedAlert:`
- `_removeAllPresentedAlerts`
- `_setProgress:forNotificationWithIdentifier:`
- `_registerForRemotePushNotificationsWithEnvironment:types:`
- `_invalidateAndUnregister`
- `deliverNotification:`
- `removeDeliveredNotification:`
- `scheduleNotification:`
- `_removeDisplayedNotification:`

```c
#include <CoreFoundation/CoreFoundation.h>
#include <objc/objc.h>
#include <objc/objc-runtime.h>

int main(int argc, char **argv)
{
    _Nullable Class NSUserNotificationCenter = objc_lookUpClass("NSUserNotificationCenter");

    unsigned int methodCount;
    _Nonnull Method *_Nullable methodList = class_copyMethodList(NSUserNotificationCenter, &methodCount);

    printf("%i\n", methodCount);

    for (int i = 0; i < methodCount; i++)
    {
        printf("%s\n", method_getName(methodList[i]));
    }
}

```

### [`NSUserNotification`](https://developer.apple.com/documentation/foundation/nsusernotification?language=objc)

Methods:

- `init`
- `isEqual:`
- `initWithCoder:`
- `encodeWithCoder:`
- `copyWithZone:`
- `setContentImage:`
- `_identityImageData`
- `_secureEncodedUserInfo`
- `_setActualDeliveryDate:`
- `_setPresented:`
- `_nextFireDate`
- `_setRemote:`
- `_setSnoozed:`
- `_setSnoozeInterval:`
- `_setSnoozedDate:`
- `_setActivationType:`
- `_areIdentifiersEqual:`
- `_hasContentImage`
- `_setIdentityImage:withIdentifier:`
- `set_identityImageData:`
- `_contentImageData`
- `set_contentImageData:`
