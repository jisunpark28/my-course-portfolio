#include <stdio.h>

int hydrogen(int atom);
int oxygen(int atom);

int main(void)
{
    int proton = (1 + 2 % 3) * 6 / 5;
    int neutron;
    printf("p = %d\n", proton);
    neutron = oxygen(proton);
    printf("p = %d, n = %d\n", proton, neutron);
    return 0;
}
int hydrogen(int atom)
{
    printf("H atom: %d\n", atom);
    return atom + 1;
}
int oxygen(int atom)
{
    int rc = atom + 1;
    printf("0 rc: %d\n", rc);
    rc += hydrogen(rc);
    printf("02 rc: %d\n", rc);
    if (rc > 5){
        printf("big\n");
    }
    else{
        printf("small\n");
    }
    return rc;
}