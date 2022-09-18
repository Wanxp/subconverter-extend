#include <string>
#include <vector>
#include <future>

#include <yaml-cpp/yaml.h>

#include "../../utils/ini_reader/ini_reader.h"
#define SUBSCRIBE_PATH "/tmp/subconverter1.txt"

const std::string SUBSCRIBE_VALUE = "suburl";


std::string saveSubscribeValue(std::string type);
std::string getSubscribeValue();


#ifndef SUBCONVERTER_SUBSCRIBE_H
#define SUBCONVERTER_SUBSCRIBE_H

#endif //SUBCONVERTER_SUBSCRIBE_H
