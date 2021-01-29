
CFLAGS = -Wall -fPIC -I../godot_headers -I../../racket-7.7/include

gdracket_rkt.c: gdracket.rkt
	 ../../racket-7.7/bin/racocs ctool -v --c-mods gdracket_rkt.c gdracket.rkt

racket_init.o: racket_init.c gdracket_rkt.c

gdracket.so: racket_init.o ../../racket-7.7/lib/libracketcs.a
	$(CC) -shared -o $@ $^ -Wl,--as-needed -luuid

install: gdracket.so
	cp gdracket.so ../test-project/gdracket/

clean:
	rm -rf gdracket.so *.o gdracket_rkt.c
