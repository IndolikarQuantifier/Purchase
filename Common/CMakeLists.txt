set(INCLUDE_FILES Constants.h Items.h DataFormat/OrderDetails.h DataFormat/OrderSummary.h)
set(SOURCE_FILE DataFormat/OrderDetails.cpp DataFormat/OrderSummary.cpp)

add_library(Common STATIC ${SOURCE_FILE})
target_include_directories(Common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Common PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
