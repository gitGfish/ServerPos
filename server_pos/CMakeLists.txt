# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
elseif (POLICY CMP0079)
  cmake_policy(SET CMP0079 NEW)
endif()

project ("server_pos")

# Include sub-projects.
add_subdirectory ("server_pos")



set(PROTOBUF_ROOT "${CMAKE_SOURCE_DIR}/server_pos/Dependencies/protobuf")
set(Protobuf_INCLUDE_DIR "${PROTOBUF_ROOT}/include")
set(Protobuf_LIBRARIES "${PROTOBUF_ROOT}/lib/libprotobuf.lib")
set(Protobuf_PROTOC_EXECUTABLE "${PROTOBUF_ROOT}/bin/protoc.exe")

message(STATUS "Protobuf root version: ${PROTOBUF_ROOT}")
# Find Protobuf
#find_package(Protobuf REQUIRED)

# Define your .proto files
set(PROTO_FILES
    ${PROTOBUF_ROOT}/my_message.proto
)

# Define output files
set(GENERATED_PROTO_SRCS ${PROTOBUF_ROOT}/my_message.pb.cc)
set(GENERATED_PROTO_HDRS ${PROTOBUF_ROOT}/my_message.pb.h)

# Add custom command to generate .cc and .h files from .proto
add_custom_command(
    OUTPUT ${GENERATED_PROTO_SRCS} ${GENERATED_PROTO_HDRS}
    COMMAND ${Protobuf_PROTOC_EXECUTABLE}
    ARGS --cpp_out=${PROTOBUF_ROOT} --proto_path=${PROTOBUF_ROOT} ${PROTO_FILES}
    DEPENDS ${PROTO_FILES}
    COMMENT "Running Protobuf compiler on ${PROTO_FILES}"
    VERBATIM
)

# Add custom target for the generated files
add_custom_target(GenerateProtos DEPENDS ${GENERATED_PROTO_SRCS} ${GENERATED_PROTO_HDRS})

# Include the generated files in the project
include_directories(${PROTOBUF_ROOT})
#add_executable(server_pos server_pos.cpp ${GENERATED_PROTO_SRCS})
add_dependencies(server_pos GenerateProtos)
#target_link_libraries(server_pos ${Protobuf_LIBRARIES})
