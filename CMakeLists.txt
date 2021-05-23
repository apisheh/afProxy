cmake_minimum_required(VERSION 3.17)
project(proxy)

set(CMAKE_CXX_STANDARD 14)

# ##################################################################################
# For CppAlgoFusionists
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -O3 -DLINUX -D_REENTRANT -DLINUX_CENTOS -DRITHMIC_PAPER_TRADING -DONLY_C_LOCALE -DRITHMIC -DDB_CONNECT_USING_MYSQL_DRIVER -DDB_TYPE_MARIADB -Wall -Wno-sign-compare -Wno-write-strings -Wpointer-arith -Winline -Wno-deprecated -fno-strict-aliasing")

include_directories(/home/ahmad/CLionProjects/cppalgofusionists)
include_directories(/home/ahmad/CLionProjects/cppalgofusionists/external/)
include_directories(/home/ahmad/CLionProjects/cppalgofusionists//external/rithmic/10.16.0.0/include)
include_directories(/home/ahmad/CLionProjects/cppalgofusionists//external/curlpp-0.8.1/include/)
include_directories(/home/ahmad/programs/mariadb10.3/include/)
include_directories(/home/ahmad/programs/mariadb10.3/server/include/)

link_directories(/home/ahmad/CLionProjects/cppalgofusionists/cmake-build-debug)
# ##################################################################################

# ##################################################################################
# For Telegram tgbot-cpp
set(Boost_USE_MULTITHREADED ON)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)
find_package(CURL)
include_directories(/usr/local/include ${OPENSSL_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    add_definitions(-DHAVE_CURL)
endif()
# ##################################################################################

add_library(${PROJECT_NAME} afproxy.cpp afproxy.h)

target_link_libraries(${PROJECT_NAME}  algofusionists ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CURL_LIBRARIES})
