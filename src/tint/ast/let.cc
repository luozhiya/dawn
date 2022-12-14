// Copyright 2022 The Tint Authors.
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

#include "src/tint/ast/let.h"

#include "src/tint/program_builder.h"

TINT_INSTANTIATE_TYPEINFO(tint::ast::Let);

namespace tint::ast {

Let::Let(ProgramID pid,
         const Source& src,
         const Symbol& sym,
         const ast::Type* ty,
         const Expression* ctor,
         AttributeList attrs)
    : Base(pid, src, sym, ty, ctor, attrs) {
    TINT_ASSERT(AST, ctor != nullptr);
}

Let::Let(Let&&) = default;

Let::~Let() = default;

const Let* Let::Clone(CloneContext* ctx) const {
    auto src = ctx->Clone(source);
    auto sym = ctx->Clone(symbol);
    auto* ty = ctx->Clone(type);
    auto* ctor = ctx->Clone(constructor);
    auto attrs = ctx->Clone(attributes);
    return ctx->dst->create<Let>(src, sym, ty, ctor, attrs);
}

}  // namespace tint::ast
