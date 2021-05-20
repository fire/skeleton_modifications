#pragma once

#include "scene/resources/skeleton_modification_3d.h"

class SkeletonModification3DLookAt : public SkeletonModification3D
{
	GDCLASS(SkeletonModification3DLookAt, SkeletonModification3D);

private:
	String bone_name = "";
	int bone_idx = -1;
	NodePath target_node;
	ObjectID target_node_cache;

	Vector3 additional_rotation = Vector3(1, 0, 0);
	bool lock_rotation_to_plane = false;
	int lock_rotation_plane = ROTATION_PLANE_X;

	void update_cache();

protected:
	static void _bind_methods();
	bool _get(const StringName& p_path, Variant& r_ret) const;
	bool _set(const StringName& p_path, const Variant& p_value);
	void _get_property_list(List<PropertyInfo>* p_list) const;

public:
	enum ROTATION_PLANE
	{
		ROTATION_PLANE_X,
		ROTATION_PLANE_Y,
		ROTATION_PLANE_Z
	};

	void execute(float delta) override;
	void setup_modification(SkeletonModificationStack3D* p_stack) override;

	void set_bone_name(String p_name);
	String get_bone_name() const;

	void set_bone_index(int p_idx);
	int get_bone_index() const;

	void set_target_node(const NodePath& p_target_node);
	NodePath get_target_node() const;

	void set_additional_rotation(Vector3 p_offset);
	Vector3 get_additional_rotation() const;

	void set_lock_rotation_to_plane(bool p_lock_to_plane);
	bool get_lock_rotation_to_plane() const;
	void set_lock_rotation_plane(int p_plane);
	int get_lock_rotation_plane() const;

	SkeletonModification3DLookAt();
	~SkeletonModification3DLookAt();
};



