# CMakeList.txt : CMake project for server_pos, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (server_pos  "src/public/Entity/Entity.h" "src/public/Entity/EntityPlayer.h" "src/public/Engine/Engine.h" "src/public/Util/Enums.h" "src/public/Util/Pos.h" "server_pos.cpp"  "src/public/Util/Math.h"  "src/public/Factory/EntityFactory.h" "src/public/Entity/EntityEnemy.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET server_pos PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
