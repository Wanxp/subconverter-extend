#include <string>

#include "../../handler/settings.h"
#include "../../utils/logger.h"
#include "../../utils/network.h"
#include "../../utils/regexp.h"
#include "../../utils/string.h"
#include "subexport.h"
#include "subscribe.h"

std::string subscribeValue = "";

std::string saveSubscribeValue(std::string value)
{
//    fileWrite(SUBSCRIBE_PATH, value, true);
    subscribeValue = value;
    return "ok";
}

std::string getSubscribeValue()
{
    std::string output, strLine;
//    output = fileGet(SUBSCRIBE_PATH, false);
    output = subscribeValue;
    return output;
}