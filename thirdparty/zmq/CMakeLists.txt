CPMAddPackage(
  NAME libzmq
  OPTIONS
    "WITH_DOC OFF"
  GIT_TAG 463ce1d02674d603301499774029874e5e380bed # v4.0.8
  GITHUB_REPOSITORY zeromq/libzmq
  GIT_SHALLOW YES
)

CPMAddPackage(
  NAME cppzmq
  GIT_TAG 6aa3ab686e916cb0e62df7fa7d12e0b13ae9fae6 # v4.2.3
  GITHUB_REPOSITORY zeromq/cppzmq
  DOWNLOAD_ONLY YES
  GIT_SHALLOW YES
)

add_library(zmq INTERFACE)

target_gothic_lib_options(libzmq-static)
target_compile_options(libzmq-static PUBLIC "/DZMQ_STATIC")

target_link_libraries(zmq INTERFACE libzmq-static ws2_32)

target_include_directories(zmq INTERFACE ${cppzmq_SOURCE_DIR} ${libzmq_SOURCE_DIR}/include)

target_tree_sources(zmq
    ROOT ${cppzmq_SOURCE_DIR}
    BASE ${cppzmq_SOURCE_DIR}
    PRIVATE
      zmq.hpp
      zmq_addon.hpp
)
