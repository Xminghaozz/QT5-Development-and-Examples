cmake_minimum_required(VERSION 3.16)

project(24_2_2_ComplexAnimation VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)


qt_add_executable(app24_2_2_ComplexAnimation
    main.cpp
)

qt_add_qml_module(app24_2_2_ComplexAnimation
    URI 24_2_2_ComplexAnimation
    VERSION 1.0
    QML_FILES Main.qml
    RESOURCES images/zhou.jpg
    QML_FILES CAnimateObj.qml
    QML_FILES MainForm.ui.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(app24_2_2_ComplexAnimation PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.app24_2_2_ComplexAnimation
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(app24_2_2_ComplexAnimation
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS app24_2_2_ComplexAnimation
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
