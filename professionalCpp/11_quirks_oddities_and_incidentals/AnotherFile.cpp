#include <iostream>

namespace {
void f();

void f() { std::cout << "f\n"; }
}  // namespace

#include <iostream>

static void f();

void f() { std::cout << "f\n"; }

// Anonymous namespace and static linkage makes the functions unavailable in
// another source file.