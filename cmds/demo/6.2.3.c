// 示例：6.2.3

int main(object me, string arg)
{
    int *a, *b = ({1});
    a = b;
    a[0] = 2;
    b += a;
    b -= a;
    printf("a = %O\nb = %O\n", a, b);

    return 1;
}
