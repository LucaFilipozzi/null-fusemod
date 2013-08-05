FUSE_PREFIX = $(HOME)/.prefix
CPPFLAGS += -D_FILE_OFFSET_BITS=64 -I$(FUSE_PREFIX)/include
CFLAGS += -fpic -ggdb3 -Wall

libfusemod_null.so: null.o
	$(CC) $(LDFLAGS) -shared -o $@ $^

clean:
	rm -f *.o *.so
