# 1. Go to project root
cd C:\Users\Matthew\Desktop\github\todo

# 2. Create a separate build folder
mkdir build
cd build

# 3. Configure CMake (generate Makefiles / build files)
cmake -G "MinGW Makefiles" ..

# 4. Build the project inside the build folder
cmake --build .

# 5. Run the executable (also from build folder)
.\todo.exe
