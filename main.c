#include <CoreFoundation/CoreFoundation.h>
#include <objc/objc-runtime.h>

CFStringRef makeCFString(char *cString) {
	return CFStringCreateWithCString(kCFAllocatorDefault, cString,
	                                 kCFStringEncodingUTF8);
}

struct Notification {
	char *title;
	char *subtitle;
	char *message;
	char *imagePath;
};

void setIcon() {
	Class bundle = objc_getClass("NSBundle");

	class_replaceMethod(bundle, sel_registerName("bundleIdentifier"),
	                    method_getImplementation(
	                        (Method) ^ { return CFSTR("com.apple.Finder"); }),
	                    NULL);
}

void sendNotification(struct Notification *notification) {
	Class bundle = objc_getClass("NSBundle");

	setIcon();

	id notificationCenter =
	    objc_msgSend((id)objc_getClass("NSUserNotificationCenter"),
	                 sel_registerName("defaultUserNotificationCenter"));

	id systemNotification =
	    objc_msgSend((id)objc_getClass("NSUserNotification"),
	                 sel_registerName("alloc"), sel_registerName("init"));

	if (notification->title != NULL) {
		objc_msgSend(systemNotification, sel_registerName("setTitle:"),
		             makeCFString(notification->title));
	}

	if (notification->subtitle != NULL) {
		objc_msgSend(systemNotification, sel_registerName("setSubtitle:"),
		             makeCFString(notification->subtitle));
	}

	if (notification->message != NULL) {
		objc_msgSend(systemNotification,
		             sel_registerName("setInformativeText:"),
		             makeCFString(notification->message));
	}

	if (notification->imagePath != NULL) {
		fputs("WARN: Adding an image is not yet implemented.\n", stderr);
	}

	objc_msgSend(systemNotification, sel_registerName("setHasActionButton:"),
	             true);

	objc_msgSend(systemNotification, sel_registerName("setActionButtonTitle:"),
	             CFSTR("Close"));

	objc_msgSend(systemNotification, sel_registerName("setOtherButtonTitle:"),
	             CFSTR("OTHER"));

	objc_msgSend(notificationCenter, sel_registerName("deliverNotification:"),
	             systemNotification);

	sleep(1);
}

int main(int argc, char **argv) {
	struct Notification notification;

	notification.title = "This is the title.";

	sendNotification(&notification);

	return 0;
}
