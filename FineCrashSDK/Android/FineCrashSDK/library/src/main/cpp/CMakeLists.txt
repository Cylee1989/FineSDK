cmake_minimum_required(VERSION 3.4.1)
project(fine_breakpad)

set(ENABLE_INPROCESS ON)
set(ENABLE_OUTOFPROCESS ON)
set(ENABLE_LIBCORKSCREW ON)
set(ENABLE_LIBUNWIND ON)
set(ENABLE_LIBUNWINDSTACK ON)
set(ENABLE_CXXABI ON)
set(ENABLE_STACKSCAN ON)

if (${ENABLE_INPROCESS})
    add_definitions(-DENABLE_INPROCESS)
endif ()
if (${ENABLE_OUTOFPROCESS})
    add_definitions(-DENABLE_OUTOFPROCESS)
endif ()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror=implicit-function-declaration")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")

# ---------------------------Breakpad编译开始---------------------------
set(BREAKPAD_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../../GoogleBreakpad)
include_directories(${BREAKPAD_ROOT}/src ${BREAKPAD_ROOT}/src/common/android/include)

file(GLOB BREAKPAD_SOURCES_COMMON
        ${BREAKPAD_ROOT}/src/client/linux/crash_generation/crash_generation_client.cc
        ${BREAKPAD_ROOT}/src/client/linux/dump_writer_common/thread_info.cc
        ${BREAKPAD_ROOT}/src/client/linux/dump_writer_common/ucontext_reader.cc
        ${BREAKPAD_ROOT}/src/client/linux/handler/exception_handler.cc
        ${BREAKPAD_ROOT}/src/client/linux/handler/minidump_descriptor.cc
        ${BREAKPAD_ROOT}/src/client/linux/log/log.cc
        ${BREAKPAD_ROOT}/src/client/linux/microdump_writer/microdump_writer.cc
        ${BREAKPAD_ROOT}/src/client/linux/minidump_writer/linux_dumper.cc
        ${BREAKPAD_ROOT}/src/client/linux/minidump_writer/linux_ptrace_dumper.cc
        ${BREAKPAD_ROOT}/src/client/linux/minidump_writer/minidump_writer.cc
        ${BREAKPAD_ROOT}/src/client/minidump_file_writer.cc
        ${BREAKPAD_ROOT}/src/common/convert_UTF.cc
        ${BREAKPAD_ROOT}/src/common/md5.cc
        ${BREAKPAD_ROOT}/src/common/string_conversion.cc
        ${BREAKPAD_ROOT}/src/common/linux/elfutils.cc
        ${BREAKPAD_ROOT}/src/common/linux/file_id.cc
        ${BREAKPAD_ROOT}/src/common/linux/guid_creator.cc
        ${BREAKPAD_ROOT}/src/common/linux/linux_libc_support.cc
        ${BREAKPAD_ROOT}/src/common/linux/memory_mapped_file.cc
        ${BREAKPAD_ROOT}/src/common/linux/safe_readlink.cc
        )

file(GLOB BREAKPAD_ASM_SOURCE ${BREAKPAD_ROOT}/src/common/android/breakpad_getcontext.S
        )

set_source_files_properties(${BREAKPAD_ASM_SOURCE} PROPERTIES LANGUAGE C)

add_library(breakpad STATIC ${BREAKPAD_SOURCES_COMMON} ${BREAKPAD_ASM_SOURCE})

target_link_libraries(breakpad log)
# ---------------------------Breakpad编译结束---------------------------

#include_directories(jni)

# 依赖Breakpad
list(APPEND LINK_LIBRARIES breakpad)

add_library(fine_breakpad SHARED
        fine_breakpad.cpp)
target_link_libraries(fine_breakpad ${LINK_LIBRARIES}
        log)