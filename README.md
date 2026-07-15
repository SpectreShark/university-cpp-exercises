# University C++ Exercises

A collection of university C++ exercises covering object-oriented programming, dynamic memory, STL containers, templates, exceptions, and file I/O.

## Programs

| Executable | Topics |
|---|---|
| `geometry_calculator` | Abstract class, inheritance, virtual methods, and geometric calculations |
| `student_records` | Structures, strings, dynamic arrays, file reading and writing, and record filtering |
| `safe_vector` | A vector-like class based on a dynamic array, operator overloading, and exceptions |
| `dynamic_vector` | Dynamic memory, indexed access, vector arithmetic, and exception handling |
| `generic_matrix` | Function templates, two-dimensional arrays, and a custom complex-number class |
| `participant_filter` | `std::list`, structures, iterators, and filtering records |

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/geometry_calculator
./build/student_records
./build/safe_vector
./build/dynamic_vector
./build/generic_matrix
./build/participant_filter
```

With a multi-configuration generator, executables can be placed in `build/Debug` or `build/Release`.
