#version 310 es

layout(local_size_x = 1, local_size_y = 1, local_size_z = 1) in;
void unused_entry_point() {
  return;
}
void f() {
  mat4 m = mat4(vec4(1.0f), vec4(1.0f), vec4(1.0f), vec4(1.0f));
  vec4 v1 = mat4(vec4(1.0f), vec4(1.0f), vec4(1.0f), vec4(1.0f))[0];
  float a = v1[0];
}

