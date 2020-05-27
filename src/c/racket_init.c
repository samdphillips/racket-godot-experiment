
#include <string.h>

#include <gdnative_api_struct.gen.h>

#include <chezscheme.h>
#include <racketcs.h>

GDN_EXPORT void godot_gdnative_init(godot_gdnative_init_options *p_options) {
    racket_boot_arguments_t boot_args;
    memset(&boot_args, 0, sizeof(boot_args));

    boot_args.boot1_path = "./petite.boot";
    boot_args.boot2_path = "./scheme.boot";
    boot_args.boot3_path = "./racket.boot";
    boot_args.exec_file = "godot";
    racket_boot(&boot_args);

}

GDN_EXPORT void godot_gdnative_singleton () {
}
