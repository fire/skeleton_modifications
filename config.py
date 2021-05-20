# config.py

def can_build(env, platform):
    return True

def configure(env):
    pass

def get_doc_classes():
    return [
        "SkeletonModification3dCCDIK",
        "SkeletonModification3dFABRIK",
        "SkeletonModification3dJiggle",
        "SkeletonModification3dLookAt",
        "SkeletonModification3dTwoBoneIK",
    ]

def get_doc_path():
    return "doc_classes"