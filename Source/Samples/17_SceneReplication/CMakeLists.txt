# Copyright (c) 2008-2022 the Urho3D project
# License: MIT

if (NOT URHO3D_NETWORK OR NOT URHO3D_PHYSICS)
    return ()
endif ()

# Define target name
set (TARGET_NAME 17_SceneReplication)

# Define source files
define_source_files (EXTRA_H_FILES ${COMMON_SAMPLE_H_FILES})

# Setup target with resource copying
setup_main_executable ()

# Setup test cases
setup_test ()
