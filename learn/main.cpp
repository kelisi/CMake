#include <stdio.h>
#include "HelloCmake.h"
#include "Opus.h"
#include "Amr.h"

int main()
{
    HelloCmake hc;
    hc.Hello();
#ifdef CODEC_OPUS
    Opus opus;
    opus.init();
#endif

#ifdef CODEC_AMR
    Amr amr;
    amr.init();
#endif

    return 0;
}