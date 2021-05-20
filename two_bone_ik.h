#pragma once

#include "scene/resources/skeleton_modification_3d.h"

///////////////////////////////////////
// SkeletonModification3DTwoBoneIK
///////////////////////////////////////

class SkeletonModification3DTwoBoneIK : public SkeletonModification3D
{
	GDCLASS(SkeletonModification3DTwoBoneIK, SkeletonModification3D);

private:
	NodePath target_node;
	ObjectID target_node_cache;

	bool use_tip_node = false;
	NodePath tip_node;
	ObjectID tip_node_cache;

	bool use_pole_node = false;
	NodePath pole_node;
	ObjectID pole_node_cache;

	String joint_one_bone_name = "";
	int joint_one_bone_idx = -1;
	String joint_two_bone_name = "";
	int joint_two_bone_idx = -1;

	bool auto_calculate_joint_length = false;
	float joint_one_length = -1;
	float joint_two_length = -1;

	float joint_one_roll = 0;
	float joint_two_roll = 0;

	void update_cache_target();
	void update_cache_tip();
	void update_cache_pole();

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

	void set_use_tip_node(const bool p_use_tip_node);
	bool get_use_tip_node() const;
	void set_tip_node(const NodePath &p_tip_node);
	NodePath get_tip_node() const;

	void set_use_pole_node(const bool p_use_pole_node);
	bool get_use_pole_node() const;
	void set_pole_node(const NodePath &p_pole_node);
	NodePath get_pole_node() const;

	void set_auto_calculate_joint_length(bool p_calculate);
	bool get_auto_calculate_joint_length() const;
	void calculate_joint_lengths();

	void set_joint_one_bone_name(String p_bone_name);
	String get_joint_one_bone_name() const;
	void set_joint_one_bone_idx(int p_bone_idx);
	int get_joint_one_bone_idx() const;
	void set_joint_one_length(float p_length);
	float get_joint_one_length() const;

	void set_joint_two_bone_name(String p_bone_name);
	String get_joint_two_bone_name() const;
	void set_joint_two_bone_idx(int p_bone_idx);
	int get_joint_two_bone_idx() const;
	void set_joint_two_length(float p_length);
	float get_joint_two_length() const;

	void set_joint_one_roll(float p_roll);
	float get_joint_one_roll() const;
	void set_joint_two_roll(float p_roll);
	float get_joint_two_roll() const;

	SkeletonModification3DTwoBoneIK();
	~SkeletonModification3DTwoBoneIK();
};


