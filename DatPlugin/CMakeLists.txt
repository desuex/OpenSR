FIND_PACKAGE(Qt5Core REQUIRED)
FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Quick REQUIRED)

SET(SOURCES

        DatPlugin.cpp
        DatManager.cpp
        DatBindings.cpp
        DatContext.cpp
        DatObject.cpp
)

SET(HEADERS 

        Dat.h
        DatPlugin.h
        DatManager.h
        DatBindings.h
        DatContext.h
        DatObject.h
)

INCLUDE_DIRECTORIES(
    ${OPENGL_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/include
    ${Qt5Gui_INCLUDE_DIRS}
    ${Qt5Widgets_INCLUDE_DIRS}
    ${Qt5Core_INCLUDE_DIRS}
)

QT5_WRAP_CPP(MOC_SOURCES ${HEADERS})

ADD_LIBRARY(datplugin SHARED ${SOURCES} ${MOC_SOURCES})
TARGET_LINK_LIBRARIES(datplugin engine)
SET_TARGET_PROPERTIES(datplugin PROPERTIES COMPILE_DEFINITIONS "OPENSR_DATPLUGIN_BUILD")

IF(WIN32)
    SET_TARGET_PROPERTIES(datplugin PROPERTIES PREFIX "")
ENDIF()
