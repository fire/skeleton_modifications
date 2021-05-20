#pragma once

#include "scene/resources/skeleton_modification_3d.h"

///////////////////////////////////////
// SkeletonModification3DFABRIK
///////////////////////////////////////

class SkeletonModification3DFABRIK : public SkeletonModification3D {
	GDCLASS(SkeletonModification3DFABRIK, SkeletonModification3D);

private:
	struct FABRIK_Joint_Data {
		String bone_name = "";
		int bone_idx = -1;
		float length = -1;
		Vector3 magnet_position = Vector3(0, 0, 0);

		bool auto_calculate_length = true;
		bool use_tip_node = false;
		NodePath tip_node = NodePath();
		ObjectID tip_node_cache;

		bool use_target_basis = false;
		float roll = 0;
	};

	Vector<FABRIK_Joint_Data> fabrik_data_chain;
	NodePath target_node;
	ObjectID target_node_cache;

	float chain_tolerance = 0.01;
	int chain_max_iterations = 10;
	int chain_iterations = 0;

	void update_target_cache();
	void update_joint_tip_cache(int p_joint_idx);

	int final_joint_idx = 0;
	Transform target_global_pose = Transform();
	Transform origin_global_pose = Transform();

	void chain_backwards();
	void chain_forwards();
	void chain_apply();

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

	int get_fabrik_data_chain_length();
	void set_fabrik_data_chain_length(int p_new_length);

	float get_chain_tolerance();
	void set_chain_tolerance(float p_tolerance);

	int get_chain_max_iterations();
	void set_chain_max_iterations(int p_iterations);

	String get_fabrik_joint_bone_name(int p_joint_idx) const;
	void set_fabrik_joint_bone_name(int p_joint_idx, String p_bone_name);
	int get_fabrik_joint_bone_index(int p_joint_idx) const;
	void set_fabrik_joint_bone_index(int p_joint_idx, int p_bone_idx);
	float get_fabrik_joint_length(int p_joint_idx) const;
	void set_fabrik_joint_length(int p_joint_idx, float p_bone_length);
	Vector3 get_fabrik_joint_magnet(int p_joint_idx) const;
	void set_fabrik_joint_magnet(int p_joint_idx, Vector3 p_magnet);
	bool get_fabrik_joint_auto_calculate_length(int p_joint_idx) const;
	void set_fabrik_joint_auto_calculate_length(int p_joint_idx, bool p_auto_calculate);
	void fabrik_joint_auto_calculate_length(int p_joint_idx);
	bool get_fabrik_joint_use_tip_node(int p_joint_idx) const;
	void set_fabrik_joint_use_tip_node(int p_joint_idx, bool p_use_tip_node);
	NodePath get_fabrik_joint_tip_node(int p_joint_idx) const;
	void set_fabrik_joint_tip_node(int p_joint_idx, NodePath p_tip_node);
	bool get_fabrik_joint_use_target_basis(int p_joint_idx) const;
	void set_fabrik_joint_use_target_basis(int p_joint_idx, bool p_use_basis);
	float get_fabrik_joint_roll(int p_joint_idx) const;
	void set_fabrik_joint_roll(int p_joint_idx, float p_roll);

	SkeletonModification3DFABRIK();
	~SkeletonModification3DFABRIK();
};
