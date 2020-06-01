#include <stdio.h>
#include "HelloCmake.h"
#include "Opus.h"

int main()
{
    HelloCmake hc;
    hc.Hello();

    Opus opus;
    opus.init();

    return 0;
}