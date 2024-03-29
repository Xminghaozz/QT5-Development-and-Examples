cmake_minimum_required(VERSION 3.16)

project(25_2_3_Mermaid VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 REQUIRED COMPONENTS Quick)


qt_add_executable(app25_2_3_Mermaid
    main.cpp
)

qt_add_qml_module(app25_2_3_Mermaid
    URI 25_2_3_Mermaid
    VERSION 1.0
    QML_FILES Main.qml
    QML_FILES MainForm.qml
    RESOURCES images/Mermaid.jpg
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(app25_2_3_Mermaid PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.app25_2_3_Mermaid
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(app25_2_3_Mermaid
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS app25_2_3_Mermaid
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
