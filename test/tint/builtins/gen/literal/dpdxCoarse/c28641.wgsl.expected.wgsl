fn dpdxCoarse_c28641() {
  var res : vec4<f32> = dpdxCoarse(vec4<f32>());
}

@fragment
fn fragment_main() {
  dpdxCoarse_c28641();
}
