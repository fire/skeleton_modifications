#include "register_types.h"

#include "core/object/class_db.h"
#include "two_bone_ik.h"
#include "jiggle.h"
#include "fabrik.h"
#include "ccdik.h"
#include "look_at.h"

void register_skeleton_modifications_types() {
	ClassDB::register_class<SkeletonModification3DTwoBoneIK>();
	ClassDB::register_class<SkeletonModification3DJiggle>();
	ClassDB::register_class<SkeletonModification3DFABRIK>();
	ClassDB::register_class<SkeletonModification3DCCDIK>();
	ClassDB::register_class<SkeletonModification3DLookAt>();
}

void unregister_skeleton_modifications_types() {
}