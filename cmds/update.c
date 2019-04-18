int main(object me, string file)
{
    object ob, env = environment(me);

    if(!wizardp(me))
    {
        return 0;
    }

    if (!file)
    {
        return notify_fail("指令：update /文件路径/文件名\n例如：update /cmds/shutdown \n");
    }

    if (file == "here")
    {
        if(env)
            file = file_name(env);
        else
            return notify_fail("你不在任何环境中。\n");
    }

    if (file == VOID_OB)
    {
        return notify_fail("你不能在 VOID_OB 里重新编译 VOID_OB。\n");
    }

    write("重新编译[" + file + "]:");

    if (ob = find_object(file))
    {
        destruct(ob);
    }

    if (objectp(load_object(file)))
    {
        write("成功!\n");
    } else
    {
        write("失败!\n");
    }

    return 1;
}
