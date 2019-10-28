#include <CoreFoundation/CoreFoundation.h>
#include <objc/objc.h>
#include <objc/objc-runtime.h>

// #define OBJC_CLASS(name) typedef struct objc_object name

void OBJC_CLASS_$_NSUserNotificationCenter();

int main(int argc, char **argv)
{
    _Nullable Class NSUserNotificationCenter = objc_lookUpClass("NSUserNotificationCenter");
    // _Nullable id notificationCenter = class_createInstance(NSUserNotificationCenter, 0);

    // _Nullable Method method =
    // class_getInstanceMethod(NSUserNotificationCenter,
    // "defaultUserNotificationCenter");

    unsigned int methodCount;
    _Nonnull Method *_Nullable methodList = class_copyMethodList(NSUserNotificationCenter, &methodCount);

    printf("%i\n", methodCount);

    for (int i = 0; i < methodCount; i++)
    {
        printf("%s\n", method_getName(methodList[i]));
    }
}
