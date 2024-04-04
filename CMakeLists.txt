cmake_minimum_required(VERSION 3.5)

project(kursovaa VERSION 0.1 LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        workerwindow.h
        workerwindow.cpp
        adminwindow.h
        adminwindow.cpp
        workermainwindow.h
        workermainwindow.cpp
        adminmainwindow.h
        adminmainwindow.cpp
        druk.h
        druk.cpp
        druk.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(kursovaa
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        adminmainwindow.ui adminwindow.ui workermainwindow.ui workerwindow.ui
        addworker.h addworker.cpp addworker.ui
    )
    find_package(Qt6 REQUIRED COMPONENTS PrintSupport)
    target_link_libraries(kursovaa PRIVATE Qt6::PrintSupport)
else()
    if(ANDROID)
        add_library(kursovaa SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(kursovaa
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(kursovaa PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.kursovaa)
endif()
set_target_properties(kursovaa PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS kursovaa
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(kursovaa)
endif()
