
#include <string.h>

#include <gdnative_api_struct.gen.h>

#include <chezscheme.h>
#include <racketcs.h>

#include "gdracket_rkt.c"

GDN_EXPORT void rkt_gdnative_init(godot_gdnative_init_options *p_options) {
    racket_boot_arguments_t boot_args;
    memset(&boot_args, 0, sizeof(boot_args));

    /* in reality we need to be able to find these packaged */
    boot_args.boot1_path = "/home/sam/projects/racket-dev/racket-godot/racket-7.7/lib/petite.boot";
    boot_args.boot2_path = "/home/sam/projects/racket-dev/racket-godot/racket-7.7/lib/scheme.boot";
    boot_args.boot3_path = "/home/sam/projects/racket-dev/racket-godot/racket-7.7/lib/racket.boot";
    boot_args.exec_file = "godot";
    racket_boot(&boot_args);
    declare_modules();
    ptr mod_name =
        Scons(Sstring_to_symbol("quote"),
                Scons(Sstring_to_symbol("gdracket"), Snil));
    ptr rkt_init_name = Sstring_to_symbol("gdracket-pre-init");

    /* XXX: the happy path */
    ptr rkt_init_proc_vals = racket_dynamic_require(mod_name, rkt_init_name);
    ptr rkt_init_proc = Scar(rkt_init_proc_vals);
    ptr rkt_init_args = Scons(p_options, Snil);
    racket_apply(rkt_init_proc, rkt_init_args);
}

GDN_EXPORT void rkt_gdnative_singleton () {
}
