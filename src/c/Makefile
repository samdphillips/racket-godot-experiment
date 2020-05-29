
CFLAGS = -Wall -fPIC -I../../godot_headers -I../../../racket-7.7/include

gdracket.so: racket_init.o ../../../racket-7.7/lib/libracketcs.a
	$(CC) -shared -o $@ $^ -Wl,--as-needed -luuid

install: gdracket.so
	cp gdracket.so ../../test-project/gdracket/

clean:
	rm -rf gdracket.so *.o
