add_library(Script_ABWithoutAB SHARED)

target_link_libraries(Script_ABWithoutAB PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_ABWithoutAB)

target_tree_sources(Script_ABWithoutAB
  PRIVATE
    Script_ABWithoutAB.cpp
)
