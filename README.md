
# EXPERIMENTAL

I'm publishing this so that if someone really wants to make a Racket Godot
extension that may have a place to start.  I can probably answer simple
questions, but otherwise the code is as-is.

Only tested on Linux.

## Downloads required

You need to download:
- https://mirror.racket-lang.org/installers/8.0/racket-8.0-src-builtpkgs.tgz
- https://downloads.tuxfamily.org/godotengine/3.2.1/Godot_v3.2.1-stable_x11.64.zip

## Install in place install Racket in racket-8.0

Build Racket with -fPIC because later we'll statically link the libracketcs.a
into a dynamic library for Godot to load.  If you don't do it this way when the
dynamic library is loaded in Godot it will be missing symbols.  There is
probably a way to make this unnecessary but I was just trying to get something
to work.

```
$ mkdir build
$ cd build/
# $ CFLAGS="-fPIC" ../configure --enable-cs
$ CFLAGS="-fPIC" ../configure
$ make
$ make install
 ```

## Additional Racket packages
For raco ctool to work the cext-lib package is needed.
```
$ ./racket-8.0/bin/racocs pkg install -i --auto cext-lib

 ```

## Chez Boot Files

In `src/racket_init.c` you'll need to change the following variables (lines
16-18) to point to the correct Chez boot files on your system.
- `boot_args.boot1_path`
- `boot_args.boot2_path`
- `boot_args.boot3_path`

## Makefile
Adjust any of the paths in the Makefile to reflect your installation.
