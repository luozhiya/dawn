#version 310 es

void f() {
  uint a = 4u;
  uvec3 b = uvec3(1u, 2u, 3u);
  uvec3 r = (4u + uvec3(1u, 2u, 3u));
}

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void main() {
  f();
  return;
}
