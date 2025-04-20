add_library(Script_MouseDrag SHARED)

target_link_libraries(Script_MouseDrag PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_MouseDrag)

target_tree_sources(Script_MouseDrag
  PRIVATE
    Script_MouseDrag.cpp
)
