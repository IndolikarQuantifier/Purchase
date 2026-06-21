cmake_minimum_required(VERSION 3.16)

project(Purchase VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Purchase
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Widgets/QuantityWidget.h Widgets/QuantityWidget.cpp Widgets/QuantityWidget.ui
        Common/DataFormat/OrderDetails.h Common/DataFormat/OrderDetails.cpp
        Common/DataFormat/OrderSummary.h Common/DataFormat/OrderSummary.cpp
        Widgets/DataUpdatation/NewItemDialog.h Widgets/DataUpdatation/NewItemDialog.cpp Widgets/DataUpdatation/NewItemDialog.ui
        Common/Constants.h
        Common/Items.h
        Common/CMakeLists.txt
        Widgets/Overlay/NavigationOverlay.h Widgets/Overlay/NavigationOverlay.cpp Widgets/Overlay/NavigationOverlay.ui
        Widgets/TakeOrder/TakeOrderMainOverlay.h Widgets/TakeOrder/TakeOrderMainOverlay.cpp
        Widgets/TakeOrder/TakeOrder.h Widgets/TakeOrder/TakeOrder.cpp Widgets/TakeOrder/TakeOrder.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Purchase APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Purchase SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Purchase
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Purchase PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Purchase)
endif()
set_target_properties(Purchase PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Purchase
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Purchase)
endif()
