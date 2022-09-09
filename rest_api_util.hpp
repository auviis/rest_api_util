
#ifndef rest_api_util_h
#define rest_api_util_h
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <iostream>
#include <map>
#include <curl/curl.h>
class RestAPIUtil
{
public:
    RestAPIUtil();
    ~RestAPIUtil();
    static std::string callRawAPI(std::string url, std::map<std::string, std::string> params, std::string method = "GET");
    static std::string callRawAPIGet(std::string url, std::map<std::string, std::string> params);
    static std::string callRawAPIPost(std::string url, std::map<std::string, std::string> params);
};

#endif /* rest_h */



