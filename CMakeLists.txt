cmake_minimum_required(VERSION 3.9)
project(caravan_ivonnegattringer)

set(CMAKE_CXX_STANDARD 11)

add_executable(caravan_ivonnegattringer
        caravan.cpp
        caravan.h
        caravan_test_driver.cpp
        general.cpp
        general.h
        mainpage.h
        pack_animal.cpp
        pack_animal.h
        shortcut.cpp
        shortcut.h
        test_caravan.cpp
        test_caravan.h
        test_pack_animal.cpp
        test_pack_animal.h)
