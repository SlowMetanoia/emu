cmake_minimum_required(VERSION 3.5)

project(emu LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED Network)

if(ANDROID)
  add_library(emu SHARED
    main.cpp
    #mainwindow.cpp
    #mainwindow.h
    #mainwindow.ui
    #series.cpp
    #series.h
    #expTest.cpp
    reggenerator.cpp
    reggenerator.h
    #form.cpp
    #form.h
    #form.ui
    #windowmanager.cpp
    #windowmanager.h
    #modbusregimitator.cpp
    #modbusregimitator.h
    #reader.cpp
    #reader.h
    configreader.cpp
    configreader.h
    journalwriter.cpp
    journalwriter.h
    pulsegenerator.cpp
    pulsegenerator.h
    initer.cpp
    initer.h
    imitatorconfig.cpp
    imitatorconfig.h
    registrconfig.cpp
    registrconfig.h
    configwriter.cpp
    configwriter.h
    RandomTypes.h
    climanager.cpp
    climanager.h
    pulsecontroller.cpp
    pulsecontroller.h
    valuegenerator.cpp
    valuegenerator.h
    valuescontroller.cpp
    valuescontroller.h
    binmessage.cpp
    binmessage.h
    outmanager.cpp
    outmanager.h
    socketwriter.cpp
    socketwriter.h
    modbuswriter.cpp
    modbuswriter.h
  )
else()
  add_executable(emu
    main.cpp
    #mainwindow.cpp
    #mainwindow.h
    #mainwindow.ui
    #series.cpp
    #series.h
    #expTest.cpp
    reggenerator.cpp
    reggenerator.h
    #form.cpp
    #form.h
    #form.ui
    #windowmanager.cpp
    #windowmanager.h
    #modbusregimitator.cpp
    #modbusregimitator.h
    #reader.cpp
    #reader.h
    configreader.cpp
    configreader.h
    journalwriter.cpp
    journalwriter.h
    pulsegenerator.cpp
    pulsegenerator.h
    initer.cpp
    initer.h
    imitatorconfig.cpp
    imitatorconfig.h
    registrconfig.cpp
    registrconfig.h
    configwriter.cpp
    configwriter.h
    RandomTypes.h
    climanager.cpp
    climanager.h
    pulsecontroller.cpp
    pulsecontroller.h
    valuegenerator.cpp
    valuegenerator.h
    valuescontroller.cpp
    valuescontroller.h
    binmessage.cpp
    binmessage.h
    outmanager.cpp
    outmanager.h
    socketwriter.cpp
    socketwriter.h
    modbuswriter.cpp
    modbuswriter.h
  )
endif()

target_link_libraries(emu PRIVATE Qt5::Widgets Qt5::Network /usr/local/include/modbus/modbus.h)
