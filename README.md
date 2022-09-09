An c++ utility net dynamic library for call API on linux.

Run on debian or centos

#update librest_api_util first

#Debian 
$sudo apt install libcurl4
$sudo cp engine/extern/rest_api_util/librest_api_util_debian_10.so /usr/local/lib
$sudo ldconfig

#CentOS
$sudo yum install curl
$sudo cp engine/extern/rest_api_util/librest_api_util_centos_7.so /usr/lib
$sudo ldconfig
