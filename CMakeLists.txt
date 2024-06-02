cmake_minimum_required(VERSION 3.5)

project(qt_project_hse VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# app icon preparation
set(MACOSX_BUNDLE_ICON_FILE appico.ico)
set(app_icon_macos "${CMAKE_CURRENT_SOURCE_DIR}/resources/appico.ico")
set_source_files_properties(${app_icon_macos} PROPERTIES
           MACOSX_PACKAGE_LOCATION "Resources")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${app_icon_macos} # adding app icon path to execute in app
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(qt_project_hse
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        car.h car.cpp
        offerwindow.h offerwindow.cpp offerwindow.ui
        guidelinedialog.h guidelinedialog.cpp guidelinedialog.ui
        datapath.h datapath.cpp datapath.ui
        profile.h profile.cpp
        profilewindow.h profilewindow.cpp profilewindow.ui
        aboutdialog.h aboutdialog.cpp aboutdialog.ui
        offersmodel.h offersmodel.cpp
        proxymodel.h proxymodel.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET qt_project_hse APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(qt_project_hse SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(qt_project_hse
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(qt_project_hse PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::Sql)
# /opt/homebrew/Cellar/libpqxx/7.9.0/lib/libpqxx-7.9.dylib
# target_link_options(qt_project_hse PUBLIC ${LIBPQXX_LDFLAGS})
# target_link_options(qt_project_hse PUBLIC ${LIBPQ_LDFLAGS})



# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.qt_project_hse)
endif()
set_target_properties(qt_project_hse PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS qt_project_hse
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(qt_project_hse)
endif()
