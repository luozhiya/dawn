fn clamp_2bd567() {
  var res : f32 = clamp(1.0, 1.0, 1.0);
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  clamp_2bd567();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  clamp_2bd567();
}

@compute @workgroup_size(1)
fn compute_main() {
  clamp_2bd567();
}
