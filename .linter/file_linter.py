import os
import subprocess
import sys


with open("git_diff.txt") as in_file:
    modified_file = sorted(in_file.read().splitlines())
    print(f"{len(modified_file)} termodifikasi")

    cpp_exts = tuple(".c .c++ .cc .cpp .cu .cuh .cxx .h .h++ .hh .hpp .hxx".split())
    cpp_files = [file for file in modified_file if file.lower().endswith(cpp_exts)]
    print(f"{len(cpp_files)} yang termodifikasi")

    if not cpp_files:
        sys.exit(0)

        subprocess.run(["clang-tidy", "--fix", "-p=build", "--extra-arg=std=c+11", *cpp_files, "--"], check=True, text=True, stderr=subprocess.STDOUT)
        subprocess.run(["clang-format", "-i", "-style=file", *cpp_files], check=True, text=True, stderr=subprocess.STDOUT)

        upper_files = [file for file in cpp_files if file != file.lower()]
        if upper_files:
            print(f"{len(upper_files)} file yang mengandung huruf besar")
            print("\n".join(upper_files) + "\n")

        space_file = [file for file in cpp_files if " " in file or "-" in file]
        if space_file:
            print(f"{len(space_file)} file yang mengandung karakter spasi atau dash")
            print("\n".join(space_file) + "\n")

        nodir_files = [file for file in cpp_files if file.count(os.sep) != 1]
        if nodir_files:
            print(f"{len(nodir_files)} file yang tidak ada dalam atau hanya satu dalam direktori")
            print("\n".join(nodir_files) + "\n")

        bad_files = len(upper_files + space_file + nodir_files)
        if bad_files:
            sys.exit(bad_files)
