#include <stdio.h>
#include "HelloCmake.h"
#include "Opus.h"
#include "Amr.h"

int main()
{
    HelloCmake hc;
    hc.Hello();

    Opus opus;
    opus.init();

    Amr amr;
    amr.init();

    return 0;
}