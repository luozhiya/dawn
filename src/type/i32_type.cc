// Copyright 2020 The Tint Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "src/type/i32_type.h"

#include "src/ast/module.h"
#include "src/clone_context.h"

TINT_INSTANTIATE_CLASS_ID(tint::type::I32);

namespace tint {
namespace type {

I32::I32() = default;

I32::I32(I32&&) = default;

I32::~I32() = default;

std::string I32::type_name() const {
  return "__i32";
}

uint64_t I32::MinBufferBindingSize(MemoryLayout) const {
  return 4;
}

uint64_t I32::BaseAlignment(MemoryLayout) const {
  return 4;
}

I32* I32::Clone(CloneContext* ctx) const {
  return ctx->dst->create<I32>();
}

}  // namespace type
}  // namespace tint
