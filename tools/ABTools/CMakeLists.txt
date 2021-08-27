INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/include
)


SET(AB_TOOL_SRCS
    ab.cpp
        WorldUnit.h
        WorldUnit.cpp
        TabWorldUnit.h
        TabWorldUnit.cpp
        TPointAB.cpp
        TPointAB.h
        Utils.cpp
        Utils.h
        windows.h
        TabObj3D.h
        TabObj3D.cpp
        TabObj3Dunit.cpp
        TabObj3Dunit.h
        TabTex.cpp
        TabTex.h
        TKeyAB.cpp
        TKeyAB.h
        ABKey.cpp
        ABKey.h
        TKeyGroupList.cpp
        TKeyGroupList.h
        ABPoint.cpp
        ABPoint.h
        ABTriangle.cpp
        ABTriangle.h
        TTriangleAB.cpp
        TTriangleAB.h
        ABLine.cpp
        ABLine.h
        TLineAB.cpp
        TLineAB.H
        WorldZone.cpp
        WorldZone.h
        TabZone.cpp
        TabZone.h
        TabZoneLink.cpp
        TabZoneLink.h
        Export.cpp
        Export.h

)

ADD_EXECUTABLE(opensr-ab-tool ${AB_TOOL_SRCS})
TARGET_LINK_LIBRARIES(opensr-ab-tool RangerQt Qt5::Core)

INSTALL(TARGETS opensr-ab-tool RUNTIME DESTINATION bin)
