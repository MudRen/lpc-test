int main(object me, string file)
{
    object ob, env = environment(me);

    if (!file)
    {
        return notify_fail("ָ�update /�ļ�·��/�ļ���\n���磺update /cmds/shutdown \n");
    }

    if (file == "here")
    {
        if (env)
            file = file_name(env);
        else
            return notify_fail("�㲻���κλ����С�\n");
    }

    if (file == VOID_OB)
    {
        return notify_fail("�㲻���� VOID_OB ����� VOID_OB��\n");
    }

    write("����[" + file + "]:");

    if (ob = find_object(file))
    {
        destruct(ob);
    }

    if (objectp(load_object(file)))
    {
        write("�ɹ�!\n");
    }
    else
    {
        write("ʧ��!\n");
    }

    return 1;
}
