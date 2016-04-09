/*
* This file defines main method for Gateway
*/

#include "Config.h"
#include "Gateway.h"

/*
* Gateway uses the ace log system to record it's log
* and debug
*/
static int Initialize_ACE_Log()
{
    return 0;
}

void init_ace_log()
{
}


int main(int argc, char** argv)
{
    Initialize_ACE_Log();

    if ( IoTGateway::instance()->Init() >= 0)
    {
        IoTGateway::instance()->Start();
        IoTGateway::instance()->Stop();
    }
    else
    {
        ACE_DEBUG((LM_DEBUG,
                    "Failed to initialize gateway, please check...\n"));
    }

    return 0;
}






