fn refract_7e02e6() {
  var res : vec4<f32> = refract(vec4<f32>(), vec4<f32>(), 1.0);
}

@vertex
fn vertex_main() -> @builtin(position) vec4<f32> {
  refract_7e02e6();
  return vec4<f32>();
}

@fragment
fn fragment_main() {
  refract_7e02e6();
}

@compute @workgroup_size(1)
fn compute_main() {
  refract_7e02e6();
}
