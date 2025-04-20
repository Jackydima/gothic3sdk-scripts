add_library(Script_CrashReport SHARED)

target_link_libraries(Script_CrashReport PRIVATE g3sdk::SDK)

target_gothic_script_options(Script_CrashReport)

target_tree_sources(Script_CrashReport
  PRIVATE
    Script_CrashReport.cpp
)
