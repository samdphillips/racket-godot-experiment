
#include <string.h>

#include <gdnative_api_struct.gen.h>

#include <chezscheme.h>
#include <racketcs.h>

GDN_EXPORT void godot_gdnative_init(godot_gdnative_init_options *p_options) {
    racket_boot_arguments_t boot_args;
    memset(&boot_args, 0, sizeof(boot_args));

    /* in reality we need to be able to find these packaged */
    boot_args.boot1_path = "/home/sam/projects/racket-dev/racket-godot/racket-7.7/lib/petite.boot";
    boot_args.boot2_path = "/home/sam/projects/racket-dev/racket-godot/racket-7.7/lib/scheme.boot";
    boot_args.boot3_path = "/home/sam/projects/racket-dev/racket-godot/racket-7.7/lib/racket.boot";
    boot_args.exec_file = "godot";
    racket_boot(&boot_args);

}

GDN_EXPORT void godot_gdnative_singleton () {
}
