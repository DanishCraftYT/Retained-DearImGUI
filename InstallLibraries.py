import shutil
import os

# get's the directory of this script.
user_dir = os.path.abspath(os.path.dirname(__file__))

# get's engine path.
rgui_path = os.path.join(user_dir, "RetainedImGUI")

# get's editor path.
example_program_path = os.path.join(user_dir, "ExampleProgram")

update_GLFW = input("do you want to update VCPKG Packages? (y/n): ").lower()

if update_GLFW == "y":
    # asks user for their vcpkg directory.
    vcpkg_dir = input("path to VCPKG installation: ")

    # exits the program if the vcpkg directory is invalid.
    if not os.path.exists(os.path.join(vcpkg_dir, "vcpkg.exe")):
        print("please specify a valid vcpkg directory")
        input("press enter to exit...")
        exit()
    
    # REINSTALLS GLFW3 PACKAGE FROM VCPKG #

    # removes the GLFW3 package.
    print("removing GLFW3 vcpkg package")
    os.system("vcpkg remove glfw3 --triplet=x64-mingw-dynamic --host-triplet=x64-mingw-dynamic")

    # installs the GLFW3 vcpkg package if it's not already installed.
    print("installing GLFW3 vcpkg package")
    os.system("vcpkg install glfw3 --triplet=x64-mingw-dynamic --host-triplet=x64-mingw-dynamic")
    
    # UPDATES GLFW #

    # contains the path to the GLFW package.
    glfw_path = os.path.join(vcpkg_dir, "packages/glfw3_x64-mingw-dynamic")

    # RETAINED IMGUI #

    # creates the "lib" folder if it doesn't exist.
    if not os.path.exists(os.path.join(rgui_path, "lib")):
        print("[RETAINED IMGUI] creating lib folder")
        os.mkdir(os.path.join(rgui_path, "lib"))
    
    # copies the "glfw3.dll" file into the "lib" folder if it's not already in that folder.
    print("[RETAINED IMGUI] getting glfw3.dll")
    shutil.copy(os.path.join(glfw_path, "bin/glfw3.dll"), os.path.join(rgui_path, "lib/"))

    # copies the "libglfw3dll.a" file into the "lib" folder if it's not already in that folder.
    print("[RETAINED IMGUI] getting libglfw3dll.a")
    shutil.copy(os.path.join(glfw_path, "lib/libglfw3dll.a"), os.path.join(rgui_path, "lib/"))

    # copies the GLFW source code into the include folder if it's not alreadt in that folder.
    print("[RETAINED IMGUI] getting GLFW source files")
    if not os.path.exists(os.path.join(rgui_path, "include/GLFW")):
        os.mkdir(os.path.join(rgui_path, "include/GLFW"))
    glfw_source_path = os.path.join(glfw_path, "include/GLFW")
    for filename in os.listdir(glfw_source_path):
        shutil.copy(os.path.join(glfw_source_path, filename), os.path.join(rgui_path, "include/GLFW/"))

    # EXAMPLE PROGRAM #

    # creates the "lib" folder if it doesn't exist.
    if not os.path.exists(os.path.join(example_program_path, "lib")):
        print("[EXAMPLE PROGRAM] creating lib folder")
        os.mkdir(os.path.join(example_program_path, "lib"))
    
    # copies the "glfw3.dll" file into the "lib" folder if it's not already in that folder.
    print("[EXAMPLE PROGRAM] getting glfw3.dll")
    shutil.copy(os.path.join(glfw_path, "bin/glfw3.dll"), os.path.join(example_program_path, "lib/"))

    # copies the "libglfw3dll.a" file into the "lib" folder if it's not already in that folder.
    print("[EXAMPLE PROGRAM] getting libglfw3dll.a")
    shutil.copy(os.path.join(glfw_path, "lib/libglfw3dll.a"), os.path.join(example_program_path, "lib/"))

    # copies the GLFW source code into the include folder if it's not alreadt in that folder.
    print("[EXAMPLE PROGRAM] getting GLFW source files")
    if not os.path.exists(os.path.join(example_program_path, "include/GLFW")):
        os.mkdir(os.path.join(example_program_path, "include/GLFW"))
    glfw_source_path = os.path.join(glfw_path, "include/GLFW")
    for filename in os.listdir(glfw_source_path):
        shutil.copy(os.path.join(glfw_source_path, filename), os.path.join(example_program_path, "include/GLFW/"))

# EXAMPLE PROGRAM #

# creates the "build" folder if it doesn't exist.
if not os.path.exists(os.path.join(example_program_path, "build/")):
    os.mkdir(os.path.join(example_program_path, "build/"))

# copies the "glfw3.dll" file into the build output folder if it isn't already in that folder or GLFW was updated.
if not os.path.exists(os.path.join(example_program_path, "build/glfw3.dll")) or update_GLFW == "y":
    print("[EXAMPLE PROGRAM] copying the glfw3.dll file to the build output folder")
    shutil.copy(os.path.join(example_program_path, "lib/glfw3.dll"), os.path.join(example_program_path, "build/"))

print("installed all libraries")

input("press enter to exit...")
