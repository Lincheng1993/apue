# Find out all the include and source files for
SRC_FILE := $(wildcard *.c)
OBJ_FILE := $(subst .c,.o,$(SRC_FILE))
TARGET := main
CFLAGS := -std=c99

.PHONY: all

all: $(TARGET)

$(TARGET): $(OBJ_FILE)
	$(CC) -o $@ $^
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm $(OBJ_FILE) $(TARGET) -f
