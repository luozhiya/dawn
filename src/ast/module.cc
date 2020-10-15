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

#include "src/ast/module.h"

#include <sstream>

#include "src/ast/type/struct_type.h"

namespace tint {
namespace ast {

Module::Module() = default;

Module::Module(Module&&) = default;

Module::~Module() = default;

Function* Module::FindFunctionByName(const std::string& name) const {
  for (const auto& func : functions_) {
    if (func->name() == name) {
      return func.get();
    }
  }
  return nullptr;
}

Function* Module::FindFunctionByNameAndStage(const std::string& name,
                                             ast::PipelineStage stage) const {
  for (const auto& func : functions_) {
    if (func->name() == name && func->pipeline_stage() == stage) {
      return func.get();
    }
  }
  return nullptr;
}

bool Module::IsValid() const {
  for (const auto& var : global_variables_) {
    if (var == nullptr || !var->IsValid()) {
      return false;
    }
  }
  for (auto* const alias : alias_types_) {
    if (alias == nullptr) {
      return false;
    }
    if (alias->type()->IsStruct() &&
        alias->type()->AsStruct()->name().empty()) {
      return false;
    }
  }
  for (const auto& func : functions_) {
    if (func == nullptr || !func->IsValid()) {
      return false;
    }
  }
  return true;
}

std::string Module::to_str() const {
  std::ostringstream out;

  out << "Module{" << std::endl;
  const auto indent = 2;
  for (const auto& var : global_variables_) {
    var->to_str(out, indent);
  }
  for (auto* const alias : alias_types_) {
    for (size_t i = 0; i < indent; ++i) {
      out << " ";
    }
    out << alias->name() << " -> " << alias->type()->type_name() << std::endl;
    if (alias->type()->IsStruct()) {
      alias->type()->AsStruct()->impl()->to_str(out, indent);
    }
  }
  for (const auto& func : functions_) {
    func->to_str(out, indent);
  }
  out << "}" << std::endl;

  return out.str();
}

}  // namespace ast
}  // namespace tint
