
CFLAGS = -Wall -fPIC -I../../godot_headers -I../../racket/racket/include

gdracket.so: racket_init.o ../../racket/racket/lib/libracketcs.a
	# $(CC) -shared -o $@ racket_init.o -Wl,--whole-archive ../../racket/racket/lib/libracketcs.a -Wl,--no-whole-archive
	$(CC) -shared -o $@ $^

install: gdracket.so
	cp gdracket.so ../../test-project/gdracket/

clean:
	rm -rf gdracket.so *.o
