#version 310 es

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void unused_entry_point() {
  return;
}
const int a = 1;
const int a__ = 2;
void f() {
  int b = 1;
  int b__ = 2;
}

