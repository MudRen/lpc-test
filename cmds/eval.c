#include <ansi.h>
inherit CLEAN_UP;

int main(object me, string arg)
{
    object eval_ob;
    string filename, file;

    filename = "/tmp/debug_eval_file.c";

    /* clean up first */
    if (file_size(filename) != -1)
        rm(filename);
    if (eval_ob = find_object(filename))
        destruct(eval_ob);

    file = "mixed eval(object me) { " + arg + "; }\n";
    write_file(filename, file, 1);
    printf("Result = %O\n", filename->eval(me));

    return 1;
}
