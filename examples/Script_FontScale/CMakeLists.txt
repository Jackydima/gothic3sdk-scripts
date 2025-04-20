add_library(Script_FontScale SHARED)

target_link_libraries(Script_FontScale PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_FontScale)

target_tree_sources(Script_FontScale
  PRIVATE
    Script_FontScale.cpp
)
