fn tan_8ce3e9() {
  var res : vec2<f32> = tan(vec2<f32>());
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  tan_8ce3e9();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  tan_8ce3e9();
}

@compute @workgroup_size(1)
fn compute_main() {
  tan_8ce3e9();
}
