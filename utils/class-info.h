#include <objc/objc-runtime.h>
#include <objc/objc.h>
#include <stdio.h>

void printInstanceVariables(Class class) {
  uint iVarCount;
  Ivar *_Nullable iVarList = class_copyIvarList(class, &iVarCount);

  for (int i = 0; i < iVarCount; i++) {
	const char *_Nullable iVarName = ivar_getName(iVarList[i]);
	const char *_Nullable iVarType = ivar_getTypeEncoding(iVarList[i]);
	printf("%s (%s)\n", iVarName, iVarType);
  }
}

void printMethodNames(Class class) {
  uint methodCount;
  Method *methodList = class_copyMethodList(class, &methodCount);

  for (int i = 0; i < methodCount; i++) {
	SEL selector = method_getName(methodList[i]);
	const char *_Nonnull name = sel_getName(selector);
	printf("%s\n", name);
  }
}

void printPropertyNames(Class class) {
  uint propertyCount;
  objc_property_t *propertyList = class_copyPropertyList(class, &propertyCount);

  for (int i = 0; i < propertyCount; i++) {
	const char *_Nonnull propertyName = property_getName(propertyList[i]);
	const char *_Nullable propertyType =
	    property_getAttributes(propertyList[i]);
	printf("%s (%s)\n", propertyName, propertyType);
  }
}

void printMethodArgumentInfo(Method method) {
  char *name = (char *)method_getName(method);
  uint argc = method_getNumberOfArguments(method);

  printf("%s\n", name);

  for (uint i = 0; i < argc; i++) {
	printf("  - %s\n", method_copyArgumentType(method, i));
  }
}

void printClassInfo(Class class) {
  puts("METHODS\n====================");
  printMethodNames(class);
  puts("\nPROPERTIES\n====================");
  printPropertyNames(class);
  puts("\nINSTANCE VARIABLES\n====================");
  printInstanceVariables(class);
}
