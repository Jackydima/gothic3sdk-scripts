add_library(Script_MonsterDamage SHARED)

target_link_libraries(Script_MonsterDamage PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_MonsterDamage)

target_tree_sources(Script_MonsterDamage
  PRIVATE
    Script_MonsterDamage.cpp
)
