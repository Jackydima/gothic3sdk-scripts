add_library(Script_Tracer SHARED)

target_link_libraries(Script_Tracer PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_Tracer)

target_tree_sources(Script_Tracer
  PRIVATE
    Script_Tracer.cpp
)
