add_library(Script_RemoteControl SHARED)

target_link_libraries(Script_RemoteControl PRIVATE g3sdk::SDK protobuf zmq)

target_gothic_script_options(Script_RemoteControl)

# zmq requires C++ exception handling
target_compile_options(Script_RemoteControl PRIVATE "/EHsc")

target_include_directories(Script_RemoteControl PRIVATE src)

target_tree_sources(Script_RemoteControl
  BASE src
  PRIVATE
    me_ipcadmin.cpp
    me_ipcadmin.h
    Script_RemoteControl.cpp

    handler/me_requesthandler.cpp
    handler/me_requesthandler.h
    handler/me_rh_entity.cpp
    handler/me_rh_entity.h
    handler/me_rh_goto.cpp
    handler/me_rh_goto.h
    handler/me_rh_heartbeat.cpp
    handler/me_rh_heartbeat.h
    handler/me_rh_property.cpp
    handler/me_rh_property.h
    handler/me_rh_spawn.cpp
    handler/me_rh_spawn.h

    proto/g3rc.pb.cc
    proto/g3rc.pb.h
)

# TODO: At first just continue to use the precompiled static libraries
# Then compile from source, see my build artifacts in zeromq-4.0.4 and protobuf-2.6.1.
