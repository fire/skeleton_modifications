#pragma once

#include "scene/resources/skeleton_modification_3d.h"

///////////////////////////////////////
// SkeletonModification3DJiggle
///////////////////////////////////////

class SkeletonModification3DJiggle : public SkeletonModification3D
{
	GDCLASS(SkeletonModification3DJiggle, SkeletonModification3D);

private:
	struct Jiggle_Joint_Data
	{
		String bone_name = "";
		int bone_idx = -1;

		bool override_defaults = false;
		float stiffness = 3;
		float mass = 0.75;
		float damping = 0.75;
		bool use_gravity = false;
		Vector3 gravity = Vector3(0, -6.0, 0);
		float roll = 0;

		Vector3 cached_rotation = Vector3(0, 0, 0);
		Vector3 force = Vector3(0, 0, 0);
		Vector3 acceleration = Vector3(0, 0, 0);
		Vector3 velocity = Vector3(0, 0, 0);
		Vector3 last_position = Vector3(0, 0, 0);
		Vector3 dynamic_position = Vector3(0, 0, 0);

		Vector3 last_noncollision_position = Vector3(0, 0, 0);
	};

	NodePath target_node;
	ObjectID target_node_cache;
	Vector<Jiggle_Joint_Data> jiggle_data_chain;

	float stiffness = 3;
	float mass = 0.75;
	float damping = 0.75;
	bool use_gravity = false;
	Vector3 gravity = Vector3(0, -6.0, 0);

	bool use_colliders = false;
	uint32_t collision_mask = 1;

	void update_cache();
	void _execute_jiggle_joint(int p_joint_idx, Node3D *target, float delta);
	void _update_jiggle_joint_data();

protected:
	static void _bind_methods();
	bool _get(const StringName &p_path, Variant &r_ret) const;
	bool _set(const StringName &p_path, const Variant &p_value);
	void _get_property_list(List<PropertyInfo> *p_list) const;

public:
	void execute(float delta) override;
	void setup_modification(SkeletonModificationStack3D *p_stack) override;

	void set_target_node(const NodePath &p_target_node);
	NodePath get_target_node() const;

	void set_stiffness(float p_stiffness);
	float get_stiffness() const;
	void set_mass(float p_mass);
	float get_mass() const;
	void set_damping(float p_damping);
	float get_damping() const;

	void set_use_gravity(bool p_use_gravity);
	bool get_use_gravity() const;
	void set_gravity(Vector3 p_gravity);
	Vector3 get_gravity() const;

	void set_use_colliders(bool p_use_colliders);
	bool get_use_colliders() const;
	void set_collision_mask(int p_mask);
	int get_collision_mask() const;

	int get_jiggle_data_chain_length();
	void set_jiggle_data_chain_length(int p_new_length);

	void set_jiggle_joint_bone_name(int joint_idx, String p_name);
	String get_jiggle_joint_bone_name(int joint_idx) const;
	void set_jiggle_joint_bone_index(int joint_idx, int p_idx);
	int get_jiggle_joint_bone_index(int joint_idx) const;

	void set_jiggle_joint_override(int joint_idx, bool p_override);
	bool get_jiggle_joint_override(int joint_idx) const;
	void set_jiggle_joint_stiffness(int joint_idx, float p_stiffness);
	float get_jiggle_joint_stiffness(int joint_idx) const;
	void set_jiggle_joint_mass(int joint_idx, float p_mass);
	float get_jiggle_joint_mass(int joint_idx) const;
	void set_jiggle_joint_damping(int joint_idx, float p_damping);
	float get_jiggle_joint_damping(int joint_idx) const;
	void set_jiggle_joint_use_gravity(int joint_idx, bool p_use_gravity);
	bool get_jiggle_joint_use_gravity(int joint_idx) const;
	void set_jiggle_joint_gravity(int joint_idx, Vector3 p_gravity);
	Vector3 get_jiggle_joint_gravity(int joint_idx) const;
	void set_jiggle_joint_roll(int joint_idx, float p_roll);
	float get_jiggle_joint_roll(int joint_idx) const;

	SkeletonModification3DJiggle();
	~SkeletonModification3DJiggle();
};

