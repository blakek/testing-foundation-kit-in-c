#include <CoreFoundation/CoreFoundation.h>
#include <objc/objc-runtime.h>
#include <objc/objc.h>
#include <stdio.h>

#include "utils/class-info.h"

int main(int argc, char **argv) {
	Class NSUserNotification = objc_getClass("NSUserNotification");
	Class NSUserNotificationCenter = objc_getClass("NSUserNotificationCenter");

	id userNotification = class_createInstance(NSUserNotification, 0);
	id userNotificationCenter =
	    class_createInstance(NSUserNotificationCenter, 0);

	SEL scheduleNotificationSelector =
	    sel_registerName("scheduleNotification:");

	Method scheduleNotification = class_getInstanceMethod(
	    NSUserNotificationCenter, scheduleNotificationSelector);

	// objc_property_t _Nullable z = class_getProperty(NSUserNotificationCenter,
	// "defaultUserNotificationCenter");

	// userNotification.title = title;
	// userNotification.subtitle = subtitle;
	// userNotification.informativeText = message;
	// userNotification.userInfo = options;

	object_setInstanceVariable(userNotification, "title",
	                           (void *_Nullable)CFSTR("Test title"));

	printClassInfo(NSUserNotificationCenter);

	method_invoke(userNotificationCenter, scheduleNotification,
	              userNotification);
}
