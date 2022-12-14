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

#ifndef SRC_TINT_AST_PARAMETER_H_
#define SRC_TINT_AST_PARAMETER_H_

#include <vector>

#include "src/tint/ast/variable.h"

namespace tint::ast {

/// A formal parameter to a function - a name for a typed value to be passed into a function.
/// Example:
///
/// ```
///   fn twice(a: i32) -> i32 {  // "a:i32" is the formal parameter
///     return a + a;
///   }
/// ```
///
/// @see https://www.w3.org/TR/WGSL/#creation-time-consts
class Parameter final : public Castable<Parameter, Variable> {
  public:
    /// Create a 'parameter' creation-time value variable.
    /// @param program_id the identifier of the program that owns this node
    /// @param source the variable source
    /// @param sym the variable symbol
    /// @param type the declared variable type
    /// @param attributes the variable attributes
    Parameter(ProgramID program_id,
              const Source& source,
              const Symbol& sym,
              const ast::Type* type,
              AttributeList attributes);

    /// Move constructor
    Parameter(Parameter&&);

    /// Destructor
    ~Parameter() override;

    /// Clones this node and all transitive child nodes using the `CloneContext`
    /// `ctx`.
    /// @param ctx the clone context
    /// @return the newly cloned node
    const Parameter* Clone(CloneContext* ctx) const override;
};

/// A list of parameters
using ParameterList = std::vector<const Parameter*>;

}  // namespace tint::ast

#endif  // SRC_TINT_AST_PARAMETER_H_
