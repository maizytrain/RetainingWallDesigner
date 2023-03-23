cmake_minimum_required(VERSION 3.23)
project(PDSRetainingWallDesigner LANGUAGES CXX VERSION 0.1.0)
configure_file(${PROJECT_NAME}Config.h.in ${PROJECT_NAME}Config.h)

FIND_PACKAGE(Qt6 REQUIRED COMPONENTS GUI Widgets )
find_package(GTest REQUIRED)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(CMAKE_AUTORCC ON)

add_library(PDSRetainingWallDesigner_Utilities STATIC)
target_sources(PDSRetainingWallDesigner_Utilities
    PRIVATE

    PUBLIC FILE_SET HEADERS
    BASE_DIRS ${PROJECT_SOURCE_DIR}
    FILES

    
)
target_compile_features(PDSRetainingWallDesigner_Utilities PUBLIC cxx_std_17)
target_link_libraries(PDSRetainingWallDesigner_Utilities PRIVATE
    Qt6::Core
)

install(TARGETS PDSRetainingWallDesigner_Utilities
    EXPORT PDSRetainingWallDesigner_Utilities
    FILE_SET HEADERS
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include)

install(EXPORT PDSRetainingWallDesigner_Utilities
    FILE PDSRetainingWallDesigner_Utilities.cmake
    NAMESPACE PDSRetainingWallDesigner_Utilities::
    DESTINATION lib/cmake/PDSRetainingWallDesigner)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "PDSPDSRetainingWallDesigner_UtilitiesConfigVersion.cmake"
    VERSION ${PDSPDSRetainingWallDesigner_Utilities_VERSION}
    COMPATIBILITY AnyNewerVersion)

install(
    FILES
        "PDSRetainingWallDesigner_UtilitiesConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/PDSRetainingWallDesigner_UtilitiesConfigVersion.cmake"
    DESTINATION lib/cmake/${PROJECT_NAME}
)




add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} 
PRIVATE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindowform.ui
    RCCantileverForm.ui
    rcc.h rcc.cpp
    concreteDrawer.h concreteDrawer.cpp
) 
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_include_directories(${PROJECT_NAME} PRIVATE)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Widgets
    Qt6::Gui
)




add_executable(PDSRetainingWallDesigner_unittests)
target_sources(PDSRetainingWallDesigner_unittests PRIVATE PDSRetainingWallDesigner_unittests.cpp)
target_include_directories(PDSRetainingWallDesigner_unittests PRIVATE "${GTEST_INCLUDE_DIRS}")

target_link_libraries(PDSRetainingWallDesigner_unittests
    PRIVATE
        ${GTEST_LIBRARIES}
        ${GTEST_MAIN_LIBRARIES}
        Qt6::Widgets
        Qt6::Gui
        PDSRetainingWallDesigner_Utilities
)

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    FILE_SET HEADERS
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include)

