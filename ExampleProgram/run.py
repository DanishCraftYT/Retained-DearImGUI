import sys
import os

if sys.platform == "win32":
    os.system(f"\"{os.path.join(os.path.dirname(os.path.abspath(__file__)), "build", "ExampleProgram.exe")}\"")
else:
    os.system(f"\"{os.path.join(os.path.dirname(os.path.abspath(__file__)), "build", "ExampleProgram")}\"")
