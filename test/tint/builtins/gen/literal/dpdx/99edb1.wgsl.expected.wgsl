fn dpdx_99edb1() {
  var res : vec2<f32> = dpdx(vec2<f32>());
}

@fragment
fn fragment_main() {
  dpdx_99edb1();
}
