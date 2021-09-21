
#include <unistd.h>

int main(int argc, char **argv)
{
    char buff[2];
    int i;

    i = 0;
    while (buff[i])
        write (1, &buff[i], 1);
    return (0);
}