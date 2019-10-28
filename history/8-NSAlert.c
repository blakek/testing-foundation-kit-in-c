/*
 * main.c
 * This program shows how to access Cocoa GUI from pure C/C++
 * and build a truly functional GUI application (although very simple).
 * 
 * Compile using:
 *   clang -framework Cocoa -o test ./try-8-NSAlert.c
 */

#include <CoreFoundation/CoreFoundation.h>
#include <objc/objc.h>
#include <objc/objc-runtime.h>

int NSRunAlertPanel(
    CFStringRef strTitle,
    CFStringRef strMsg,
    CFStringRef strButton1,
    CFStringRef strButton2,
    CFStringRef strButton3,
    ...);

void main(int argc, char **argv)
{
    NSRunAlertPanel(CFSTR("Testing"),
                    CFSTR("This is a simple test to display NSAlertPanel."),
                    CFSTR("OK"), NULL, NULL);
}
