CC ?= clang
SOURCES = file_ops.c logger.c server_response.c main.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = notify-testing
CFLAGS = -framework Foundation

default: $(TARGET)
all: notify-testing

dev: | clean all
	./$(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -o notify-testing main.c
	@echo "Successfully built"

clean:
	$(RM) *.o
	$(RM) $(TARGET)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
