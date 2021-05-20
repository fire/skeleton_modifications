#pragma once
#include "scene/resources/skeleton_modification_3d.h"

///////////////////////////////////////
// SkeletonModification3DCCDIK
///////////////////////////////////////

class SkeletonModification3DCCDIK : public SkeletonModification3D {
	GDCLASS(SkeletonModification3DCCDIK, SkeletonModification3D);

private:
	enum CCDIK_Axes {
		AXIS_X,
		AXIS_Y,
		AXIS_Z
	};

	struct CCDIK_Joint_Data {
		String bone_name = "";
		int bone_idx = -1;
		int ccdik_axis = 0;

		bool enable_constraint = false;
		float constraint_angle_min = 0;
		float constraint_angle_max = (2.0 * Math_PI);
		bool constraint_angles_invert = false;
	};

	Vector<CCDIK_Joint_Data> ccdik_data_chain;
	NodePath target_node;
	ObjectID target_node_cache;

	NodePath tip_node;
	ObjectID tip_node_cache;

	bool use_high_quality_solve = true;

	void update_target_cache();
	void update_tip_cache();

	void _execute_ccdik_joint(int p_joint_idx, Node3D *target, Node3D *tip);

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

	void set_tip_node(const NodePath &p_tip_node);
	NodePath get_tip_node() const;

	void set_use_high_quality_solve(bool p_solve);
	bool get_use_high_quality_solve() const;

	String get_ccdik_joint_bone_name(int p_joint_idx) const;
	void set_ccdik_joint_bone_name(int p_joint_idx, String p_bone_name);
	int get_ccdik_joint_bone_index(int p_joint_idx) const;
	void set_ccdik_joint_bone_index(int p_joint_idx, int p_bone_idx);
	int get_ccdik_joint_ccdik_axis(int p_joint_idx) const;
	void set_ccdik_joint_ccdik_axis(int p_joint_idx, int p_axis);
	bool get_ccdik_joint_enable_constraint(int p_joint_idx) const;
	void set_ccdik_joint_enable_constraint(int p_joint_idx, bool p_enable);
	float get_ccdik_joint_constraint_angle_min(int p_joint_idx) const;
	void set_ccdik_joint_constraint_angle_min(int p_joint_idx, float p_angle_min);
	float get_ccdik_joint_constraint_angle_max(int p_joint_idx) const;
	void set_ccdik_joint_constraint_angle_max(int p_joint_idx, float p_angle_max);
	bool get_ccdik_joint_constraint_invert(int p_joint_idx) const;
	void set_ccdik_joint_constraint_invert(int p_joint_idx, bool p_invert);

	int get_ccdik_data_chain_length();
	void set_ccdik_data_chain_length(int p_new_length);

	SkeletonModification3DCCDIK();
	~SkeletonModification3DCCDIK();
};
