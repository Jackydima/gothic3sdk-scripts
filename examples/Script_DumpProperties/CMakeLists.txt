add_library(Script_DumpProperties SHARED)

target_link_libraries(Script_DumpProperties PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_DumpProperties)

# picojson requires C++ exception handling
target_compile_options(Script_DumpProperties PRIVATE "/EHsc")

target_tree_sources(Script_DumpProperties
  PRIVATE
    Script_DumpProperties.cpp

  BASE picojson
  PRIVATE
    inttypes.h
    picojson.h
)
