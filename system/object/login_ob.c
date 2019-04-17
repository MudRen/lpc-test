/*****************************************************************************
Copyright: 2019, Mud.Ren
File name: login_ob.c
Description: ��ҵ�¼���߶���ʵ��ָ�������
Author: xuefeng
Version: v1.0
Date: 2019-04-18
*****************************************************************************/
int command_hook(string arg);

void logon()
{
    write(read_file(WELCOME));
    set_heart_beat(1);
    enable_wizard();
    enable_commands();
    add_action("command_hook", "", 1);
}

int command_hook(string arg)
{
    string cmd;
    object cmd_ob;

    cmd = CMD_PATH + query_verb();

    cmd_ob = load_object(cmd);
    if (cmd_ob) {
        return (int)cmd_ob->main(this_object(), arg);
    } else {
        return notify_fail("ָ����� T_T\n");
    }
}
