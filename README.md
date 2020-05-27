
Downloads:

https://mirror.racket-lang.org/installers/7.7/racket-minimal-7.7-x86_64-linux-cs.sh
https://downloads.tuxfamily.org/godotengine/3.2.1/Godot_v3.2.1-stable_x11.64.zip

Install in place install Racket in
$HOME/racket-godot/racketcs-7.7

```

# for raco ctool
$ ./racketcs-7.7/bin/raco pkg install -i --auto cext-lib

 ```

OK minimal install is missing the library file to link with.  Building from source.


### Add Racket submodule
```
$ git submodule add git@github.com:racket/racket.git
$ cd racket
$ git checkout v7.7
$ git add racket
```


### Build Racket CS
```
$ make cs-in-place RACKET=$(which racket)
```

Missing uuid.h file :(

```
$ sudo apt-get install uuid-dev
```

Ok now this works...

```
$ make cs-in-place RACKET=$(which racket)
```
