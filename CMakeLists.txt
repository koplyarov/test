project(kda-test)

find_package(Threads)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc")
else()
    add_definitions(-Wall)
    add_definitions(-std=c++11)
endif()

add_definitions(-D_GLIBCXX_DEBUG)

set(TEST_CORE_SRC
    test/ScopedTest.cpp
    test/TestContext.cpp
    test/TestEngine.cpp
    test/Tests.cpp
    test/utils/Logger.cpp
    test/utils/TypeInfo.cpp
)

add_library(test-core ${TEST_CORE_SRC})
target_link_libraries(test-core ${CMAKE_THREAD_LIBS_INIT})
