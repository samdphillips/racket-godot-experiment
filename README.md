
Downloads:

v-- fixme: use minimal source install w/ built packages
https://mirror.racket-lang.org/installers/7.7/racket-minimal-7.7-x86_64-linux-cs.sh


https://downloads.tuxfamily.org/godotengine/3.2.1/Godot_v3.2.1-stable_x11.64.zip

Install in place install Racket in racket-godot/racket-7.7

Missing uuid.h file :(

```
$ sudo apt-get install uuid-dev
```

```
$ mkdir build
$ cd build/
$ CFLAGS="-fPIC" ../configure --enable-cs
$ make cs
$ make install-cs
 ```

```
# for raco ctool
$ ./racket-7.7/bin/racocs pkg install -i --auto cext-lib

 ```


