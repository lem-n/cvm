cmake_minimum_required(VERSION 3.0.0)
project(cvm VERSION 0.1.0)

include(CTest)
enable_testing()


set(SOURCES
vm/main.c
vm/bytecode.c
vm/flags.c
vm/instr.c
vm/trace.c
vm/vm.c
parser/parser.c
parser/putils.c
parser/carg_parser.c
parser/arghandler.c)

add_executable(cvm ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
