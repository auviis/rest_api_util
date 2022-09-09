#include "rest_api_util.hpp"
#include "json.hpp"
using json = nlohmann::json;
//CentOS (7):
//$sudo cp librest_api_util_centos_7.so /usr/lib/
//$sudo ldconfig
//Debian (10):
//$sudo cp librest_api_util_debian_10.so /user/local/lib
//$sudo ldconfig
//macos: $gcc -std=c++11  -g -Wall -Wextra -pedantic -Werror -target x86_64-apple-darwin -lstdc++ -lcurl  -lrest_api_util test.cpp -o test
//linux: $gcc -std=c++11  -g -Wall -Wextra -pedantic test.cpp -o test -lstdc++ -lcurl  -lrest_api_util 

int track_me(){
    std::map<std::string, std::string> params;
    params.insert({"engine","test_engine"});
    params.insert({"module","main"});
    params.insert({"build_date","2022-09-09"});
    std::string response = RestAPIUtil::callRawAPI("http://id.oneteam.vn/api/engine/notify",params,"POST");
    //printf("response: %s\n",response.c_str());
    int status = 0;
    try {
        auto js = nlohmann::json::parse(response, nullptr, false);
        if (!js["status"].is_null()){
            status = js["status"].get<int>();
        }
    }
    catch (nlohmann::json::exception e) {
        //printf("json parse error: %s\n", e.what());
        //return 0;
    }
    //printf("status: %d\n",status);
    return status;
}

int main(){
    int status = track_me();
    return status;
}