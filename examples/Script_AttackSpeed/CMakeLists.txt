add_library(Script_AttackSpeed SHARED)

target_link_libraries(Script_AttackSpeed PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_AttackSpeed)

target_tree_sources(Script_AttackSpeed
  PRIVATE
    Script_AttackSpeed.cpp
)
