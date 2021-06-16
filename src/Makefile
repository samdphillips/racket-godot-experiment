
RACKET_VERSION = 8.0.0.3
RACKET_INSTALL = ../../racket-$(RACKET_VERSION)

RACO = $(RACKET_INSTALL)/bin/raco

CFLAGS = -Wall -fPIC -I../godot_headers -I$(RACKET_INSTALL)/include

gdracket_rkt.c: gdracket.rkt
	 $(RACO) ctool -v --c-mods gdracket_rkt.c gdracket.rkt

racket_init.o: racket_init.c gdracket_rkt.c

gdracket.so: racket_init.o $(RACKET_INSTALL)/lib/libracketcs.a
	$(CC) -shared -o $@ $^ -Wl,--as-needed -luuid

install: gdracket.so
	cp gdracket.so ../test-project/gdracket/

clean:
	rm -rf gdracket.so *.o gdracket_rkt.c
