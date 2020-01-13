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
	class_replaceMethod(objc_getClass("NSBundle"),
	                    sel_registerName("bundleIdentifier"),
	                    method_getImplementation(
	                        (Method) ^ { return CFSTR("com.apple.Finder"); }),
	                    NULL);
}

void sendNotification(struct Notification *notification) {
	Class bundle = objc_getClass("NSBundle");

	setIcon();

	void *(*callMethod)(id, SEL) = (void *(*)(id, SEL))objc_msgSend;
	void *(*alloc)(id, SEL, SEL) = (void *(*)(id, SEL, SEL))objc_msgSend;

	void *(*setTextValue)(id, SEL, CFStringRef) =
	    (void *(*)(id, SEL, CFStringRef))objc_msgSend;

	void *(*setBooleanValue)(id, SEL, Boolean) =
	    (void *(*)(id, SEL, Boolean))objc_msgSend;

	void *(*setObjectValue)(id, SEL, id) = (void *(*)(id, SEL, id))objc_msgSend;

	id notificationCenter =
	    callMethod((id)objc_getClass("NSUserNotificationCenter"),
	               sel_registerName("defaultUserNotificationCenter"));

	id systemNotification =
	    alloc((id)objc_getClass("NSUserNotification"),
	          sel_registerName("alloc"), sel_registerName("init"));

	if (notification->title != NULL) {
		setTextValue(systemNotification, sel_registerName("setTitle:"),
		             makeCFString(notification->title));
	}

	if (notification->subtitle != NULL) {
		setTextValue(systemNotification, sel_registerName("setSubtitle:"),
		             makeCFString(notification->subtitle));
	}

	if (notification->message != NULL) {
		setTextValue(systemNotification,
		             sel_registerName("setInformativeText:"),
		             makeCFString(notification->message));
	}

	if (notification->imagePath != NULL) {
		fputs("WARN: Adding an image is not yet implemented.\n", stderr);
	}

	setBooleanValue(systemNotification, sel_registerName("setHasActionButton:"),
	                true);

	setTextValue(systemNotification, sel_registerName("setActionButtonTitle:"),
	             CFSTR("Close"));

	setTextValue(systemNotification, sel_registerName("setOtherButtonTitle:"),
	             CFSTR("OTHER"));

	setObjectValue(notificationCenter, sel_registerName("deliverNotification:"),
	               systemNotification);

	sleep(1);
}

int main(int argc, char **argv) {
	struct Notification notification;

	notification.title = "This is the title.";

	sendNotification(&notification);

	return 0;
}
