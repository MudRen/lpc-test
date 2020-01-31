/**
 * sockets 相关测试
 */
void close_callback(int fd);

int main(object me, string arg)
{
    int s, err, mode = atoi(arg);

    // 创建一个 efun socket 连接
    s = socket_create(mode, "read_callback", "close_callback");
    debug("【服务器】socket_create : " + s);
    if (s < 0)
    {
        debug("【服务器】socket_create error : " + socket_error(s));
        close_callback(s);
    }
    else
    {
        if (mode != 2 && mode != 4)
        {
            // 绑定端口到 socket 连接
            err = socket_bind(s, 5000);
            debug("【服务器】socket_bind : " + err);
            if (err < 0)
            {
                debug("【服务器】socket_bind error : " + socket_error(err));
                close_callback(s);
            }
            else
            {
                // 监听一个 socket 连接
                err = socket_listen(s, "listen_callback");
                debug("【服务器】socket_listen : " + err);
                if (err < 0)
                {
                    debug("【服务器】socket_listen error : " + socket_error(err));
                    close_callback(s);
                }
                else
                {
                    write("【系统提示】TCP Socket 服务已启动:" + socket_address(s, 1) + "\n");
                }
            }
        }
        else
        {
            write("【系统提示】UDP Socket 服务已启动:" + socket_address(s) + "\n");
        }
    }
    return 1;
}


void listen_callback(int fd)
{
    int s;
    debug("【服务器】listen_callback:" + fd);
    // 在一个 socket 上接受连接
    s = socket_accept(fd, "read_callback", "write_callback");
    debug("【服务器】socket_accept : " + s);
    if (s < 0)
    {
        debug("【服务器】socket_accept error : " + socket_error(s));
        close_callback(s);
    }
    else
        socket_write(s, "欢迎连接到mud.ren服务器!^_^\n");
}

void read_callback(int fd, mixed message)
{
    debug("【服务器】read_callback : " + fd);
    shout("【服务器】" + message);
}

void close_callback(int fd)
{
    debug("【服务器】close_callback : " + fd);
    debug("【服务器】socket_close : " + socket_close(fd));
}
