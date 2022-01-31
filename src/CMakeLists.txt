add_executable(pe
    main.cpp
    prob1.cpp)

if(MSVC)
    target_compile_options(pe PRIVATE /W4 /WX)
else()
    target_compile_options(pe PRIVATE -Wall -Wextra -Werror)
endif()

