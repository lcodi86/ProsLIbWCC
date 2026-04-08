# x16-PRos Library

A lightweight and efficient C library specifically designed for the **x16-PRos** operating system. It provides a comprehensive interface to the system API, optimized for the **Open Watcom v2 (wcc/wpp)** compiler suite.

---

## Quick Links
* [**Full API Documentation**](https://github.com/PRoX2011/x16-PRos/blob/main/docs/API.md)
* [**Header File**](include/pros.h) — API definitions and constants
* [**Source Code**](src/pros.c) — Implementation details
* [**Test Suite**](test/main.c) — Full usage examples

---

## Features
* **Full API Coverage:** Seamless access to all x16-PRos system calls.
* **Compiler Optimized:** Tailored for **Open Watcom v2** (`wcc` and `wpp`) for maximum compatibility and performance.
* **Zero Overhead:** Minimal footprint, keeping your binaries small and fast.

## Usage Example

To see the library in action, check out the implementation in `test/main.c`. Here is a basic snippet of how to include and use the API:

```c
#include "pros.h"

void main() {
    print_string("Hello, world!\n");
}
```

## Development & Testing
The core logic is split between:

* `include/pros.h`: The main interface for your projects.
* `src/pros.c`: The underlying wrapper logic.

For a deep dive into how everything works, we recommend exploring the [API Reference](https://github.com/PRoX2011/x16-PRos/blob/main/docs/API.md).

---
*Developed for the x16-PRos ecosystem using Open Watcom v2.*
