add_executable(pe
    main.cpp
    Problem1.cpp
    Problem2.cpp
    Problem3.cpp
    Problem4.cpp
    Problem5.cpp
    Problem6.cpp
    Problem7.cpp
    Problem8.cpp
    Problem9.cpp
    Problem10.cpp
    Problem11.cpp)

if(MSVC)
    target_compile_options(pe PRIVATE /W4 /WX)
else()
    target_compile_options(pe PRIVATE -Wall -Wextra -Werror)
endif()

target_link_libraries(pe
    InCommandLib
)
