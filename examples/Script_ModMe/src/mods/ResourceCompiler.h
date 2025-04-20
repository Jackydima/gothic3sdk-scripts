#pragma once

#include <g3sdk/SharedBase.h>

namespace ResourceCompiler
{
GEBool CreateCollisionMesh(bCString const &a_strMeshName, bCString const &a_strColMeshPath, GEBool a_bConvex,
                           bCVector const *a_Scaling = 0);
}
