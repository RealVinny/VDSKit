cmake_minimum_required(VERSION 3.16)
project(ArrayList C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)

# 1) pega todos os .c recursivamente
file(GLOB_RECURSE VDSKIT_SOURCES CONFIGURE_DEPENDS
        ${CMAKE_SOURCE_DIR}/src/*.c)

# 2) builda a biblioteca (estática). Quer .so? mude STATIC -> SHARED
add_library(vdskit STATIC
        src/Arrays/Arrays.c
        src/LinkedLists/doubeLinked/doubleLinked.c
        src/LinkedLists/singleLinked/singleLinked.c
        src/Queue/Queue.c
        src/Stack/dynamicStack/dynamicStack.c
        src/Stack/staticStack/staticStack.c

)

target_compile_options(vdskit PRIVATE
        -Wall -Wextra -Wpedantic
        -Wmissing-prototypes -Wstrict-prototypes
        -Werror=implicit-function-declaration)



target_include_directories(vdskit PUBLIC ${CMAKE_SOURCE_DIR}/include)

# 3) executável de exemplo (ajuste o main)
add_executable(app testing.c)
target_link_libraries(app PRIVATE vdskit)

# (opcional) warnings úteis
target_compile_options(vdskit PRIVATE -Wall -Wextra -Werror -Wpedantic)
target_compile_options(app PRIVATE -Wall -Wextra -Wpedantic)
