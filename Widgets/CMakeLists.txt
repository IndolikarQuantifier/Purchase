
set(SOURCE_FILES
    QuantityWidget.cpp
    TakeOrder/TakeOrder.cpp
    TakeOrder/TakeOrderMainOverlay.cpp
    Overlay/NavigationOverlay.cpp
    DataUpdatation/NewItemDialog.cpp
)

set(INCLUDE_DIR
    ${CMAKE_CURRENT_SOURCE_DIR}/Overlay
)

qt_wrap_ui(UI_FILES
    QuantityWidget.ui
    TakeOrder/TakeOrder.ui
    Overlay/NavigationOverlay.ui
    DataUpdatation/NewItemDialog.ui
)

qt_add_library(Widgets STATIC ${SOURCE_FILES} ${UI_FILES})
target_include_directories(Widgets PUBLIC  ${INCLUDE_DIR})
target_link_libraries(Widgets PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Common)
