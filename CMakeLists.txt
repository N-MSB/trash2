cmake_minimum_required(VERSION 3.2)

project(homework2 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

#project(homework2) # VERSION ${VERSION_NUMBER})

#set (homework2_VERSION_MAJOR 0)
#set (homework2_VERSION_MINOR 0)
#set (homework2_VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})

#if("$ENV{TRAVIS_BUILD_NUMBER}" STREQUAL "")
#set(homework2_VERSION_PATCH 42)
#else()
#set(homework2_VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})
#endif()

add_subdirectory(src)
add_subdirectory(lib)
add_subderictory(test)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

enable_testing()

add_test(test test/test)