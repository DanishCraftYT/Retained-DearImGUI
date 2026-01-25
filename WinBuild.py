import shutil
import os

example_program_dir_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "ExampleProgram")
example_program_build_path = os.path.join(example_program_dir_path, "build")

# RETAINED IMGUI #

# builds the retained imgui if the user wants to.
if input("Build retained imgui? (y/n): ").lower() == "y":
    rgui_dir_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "RetainedImGUI")
    rgui_build_path = os.path.join(rgui_dir_path, "build")

    print("building retained imgui.")

    # builds the CMake project and creates the library.
    if os.system(f"cmake -S \"{rgui_dir_path}\" -B \"{rgui_build_path}\" -G \"MinGW Makefiles\"") != 0:
        print("retained imgui CMake build failed.")
        exit(1)

    if os.system(f"cmake --build \"{rgui_build_path}\"") == 2:
        print("retained imgui build failed.")
        exit(1)

    # EXAMPLE PROGRAM #
    
    print("copying retained imgui library to example program directory")

    # copies the library to the example program library directory.
    shutil.copy(os.path.join(rgui_build_path, "libRetainedImGUI.a"), os.path.join(example_program_dir_path, "lib/"))

    print("copying retained imgui headers to example program directory")

    # copies all the headers to the example program "include/RetainedImGUI" directory.
    shutil.copytree(os.path.join(rgui_dir_path, "src"), os.path.join(example_program_dir_path, "include", "RetainedImGUI"), dirs_exist_ok=True, ignore=shutil.ignore_patterns("*.cpp", "*.c"))

# EXAMPLE PROGRAM #

print("building example program.")

# builds the CMake project and creates the executable.
if os.system(f"cmake -S \"{example_program_dir_path}\" -B \"{example_program_build_path}\" -G \"MinGW Makefiles\"") != 0:
    print("example program CMake build failed.")
    exit(1)

if os.system(f"cmake --build \"{example_program_build_path}\"") != 0:
    print("example program build failed.")
    exit(1)

input("press enter to exit...")
exit(0)
