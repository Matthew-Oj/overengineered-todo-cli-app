# 1. Use a lightweight Ubuntu image
FROM ubuntu:22.04

# 2. Install dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    make \
    git \
    && rm -rf /var/lib/apt/lists/*

# 3. Set working directory
WORKDIR /app

# 4. Copy only CMakeLists.txt first to use caching
COPY CMakeLists.txt .

# 5. Create build directory
RUN mkdir build

# 6. Copy source and include files (later, so Docker caches CMake config if CMakeLists.txt unchanged)
COPY src/ ./src/
COPY include/ ./include/

# 7. Build the project
RUN cd build && cmake .. && cmake --build .

# 8. Default command
CMD ["./build/todo"]
