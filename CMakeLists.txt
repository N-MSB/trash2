cmake_minimum_required(VERSION 3.2)

project(homework2 VERSION 0.0.${VERSION_NUMBER})

if("$ENV{TRAVIS_BUILD_NUMBER}" STREQUAL "")
set(VERSION_NUMBER "42")
else()
set(VERSION_NUMBER "$ENV{TRAVIS_BUILD_NUMBER}")
endif()

##project(homework2 VERSION_NUMBER) 0.0.$ENV{TRAVIS_BUILD_NUMBER})


add_subdirectory(src)
add_subdirectory(lib)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

