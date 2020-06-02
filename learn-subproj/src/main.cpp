#include <stdio.h>
#include "Opus.h"
#include "Amr.h"

#include "tool.h"

int main()
{
#ifdef CODEC_OPUS
    Opus opus;
    opus.init();
#endif

#ifdef CODEC_AMR
    Amr amr;
    amr.init();
#endif

    //call c function
    calledByCpp();

    return 0;
}