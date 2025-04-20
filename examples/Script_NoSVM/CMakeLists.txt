add_library(Script_NoSVM SHARED)

target_link_libraries(Script_NoSVM PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_NoSVM)

target_tree_sources(Script_NoSVM
  PRIVATE
    Script_NoSVM.cpp
)
