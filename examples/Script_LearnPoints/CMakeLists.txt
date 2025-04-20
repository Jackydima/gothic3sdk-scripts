add_library(Script_LearnPoints SHARED)

target_link_libraries(Script_LearnPoints PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_LearnPoints)

target_tree_sources(Script_LearnPoints
  PRIVATE
    Script_LearnPoints.cpp
)
