# Slim - C++ Logging Library

## Project Overview

Slim is a lightweight, high-performance C++20/23 logging library with modular architecture.

## Build Instructions

### Prerequisites

- C++20 or newer (C++23 recommended for modular features)
- CMake 3.30+
- vcpkg (bundled in `ext/vcpkg`)
- Clang or GCC

### Configure and Build (Preset Preferred)

```bash
# Configure with preset (recommended)
cmake --preset silm-unix-llvm-cpp20

# Build
cmake --build out/silm-unix-llvm-cpp20

# Run tests
ctest --test-dir out/silm-unix-llvm-cpp20
```

## Project Structure

```
CMakeLists.txt              Main build configuration
CMakePresets.json           CMake presets
vcpkg.json                  Package manifest
.clang-format               Code style configuration
include/slim/               Public headers
  Slim.hpp                  Main header (exported with SLIM_EXPORT_HEADERS)
  CMakeLists.txt
src/                        Source files and modules
  Slim.cpp
  Slim.ixx                  Main module interface
  CMakeLists.txt
  core/                     Core library components
cmake/                      CMake modules
  SlimOptions.cmake         Build options
test/ut/                    Unit tests
  CMakeLists.txt
ext/vcpkg/                  vcpkg package manager
```

## CMake Presets

| Preset | Compiler | Standard | Notes |
|--------|----------|----------|-------|
| `silm-unix-llvm-cpp20` | LLVM 17+ | C++20 | Default Unix preset |
| `silm-unix-gnu-cpp20` | GCC 13+ | C++20 | Inherits from LLVM preset |

Base presets (hidden):
- `vcpkg` - Sets vcpkg toolchain
- `ninja` - Uses Ninja generator
- `vs2022` - Visual Studio 17 2022
- `vs2026` - Visual Studio 18 2026

## CMake Options

### Feature Options

| Option | Default | Description |
|--------|---------|-------------|
| `SLIM_NO_EXCEPTIONS` | OFF | Disable C++ exceptions |
| `SLIM_NO_THREAD_NAME_SUPPORT` | OFF | Disable thread name support |
| `SLIM_USE_ASSERTIONS` | OFF | Enable assertions in Release builds |
| `SLIM_USE_SEQUENTIAL_THREAD_ID` | OFF | Use sequential thread IDs instead of OS API |
| `SLIM_USE_MODULAR_STL` | OFF | Use C++23 STL modules (**requires C++23 or newer**) |
| `SLIM_USE_VCPKG_FMTLIB` | OFF | Use fmtlib from vcpkg |
| `SLIM_USE_SYSTEM_FMTLIB` | OFF | Use system-installed fmtlib |
| `SLIM_USE_SYSTEM_GTEST` | OFF | Use system-installed GTest |

### Build Options

| Option | Default | Description |
|--------|---------|-------------|
| `SLIM_EXPORT_HEADERS` | OFF | Export headers for alternative integration |
| `SLIM_BUILD_TESTS` | OFF | Build unit tests |
| `SLIM_BUILD_EXAMPLES` | OFF | Build example programs |
| `SLIM_CODE_COVERAGE` | OFF | Enable code coverage reporting |

### Sanitizer Options (LLVM only)

| Option | Default | Description |
|--------|---------|-------------|
| `SLIM_ENABLE_VALGRIND` | OFF | Use Valgrind for memory checking |
| `SLIM_ENABLE_ASAN` | OFF | Enable AddressSanitizer |
| `SLIM_ENABLE_TSAN` | OFF | Enable ThreadSanitizer |

## Code Style

- **Format**: WebKit-based style (see `.clang-format`)
- **Column limit**: 120
- **Indent**: 4 spaces
- Apply formatting before committing:
  ```bash
  find include src test -name "*.cpp" -o -name "*.hpp" -o -name "*.ixx" | xargs clang-format -i
  ```

## Testing

```bash
# Enable tests during configure
cmake --preset silm-unix-llvm-cpp20 -DSLIM_BUILD_TESTS=ON

# Run with ctest
ctest --test-dir out/silm-unix-llvm-cpp20 --output-on-failure
```

## Git Workflow

### Commit Style

- **format**: `<type>[(<scope>)]: <subject>`
- **types**: `feat`, `fix`, `doc`, `style`, `refactor`, `test`, `chore`
- **subject**: lowercase, no period at end
- **message body**: mandatory for multiple file changed, optional for single file changed

Examples:
```
feat(core): add thread-safe logger
fix: correct timestamp padding
doc(readme): update build instructions
```
