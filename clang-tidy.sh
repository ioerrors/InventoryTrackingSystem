# Configuration options for clang-tidy
# CSS Linux machines, Sep 2019: LLVM version 3.8.1
#
# usage: clang-tidy *.cpp -- -std=c++14
#
#
---
# See https://clang.llvm.org/extra/clang-tidy/#using-clang-tidy for all possible checks
Checks: '*,-fuchsia-*,-cppcoreguidelines-owning-memory,-cppcoreguidelines-pro-bounds-array-to-pointer-decay,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-google-build-using-namespace,-hicpp-no-array-decay,-modernize-use-trailing-return-type,-llvm-header-guard,-cert-err60-cpp,-cppcoreguidelines-pro-bounds-constant-array-index,-google-global-names-in-headers'

WarningsAsErrors:  '*'
HeaderFilterRegex: '.*'

CheckOptions:
 - { key: readability-identifier-naming.ClassCase,           value: CamelCase  }
 - { key: readability-identifier-naming.StructCase,          value: CamelCase  }
 - { key: readability-identifier-naming.EnumCase,            value: CamelCase  }
 - { key: readability-identifier-naming.GlobalConstantCase,  value: UPPER_CASE }

 - { key: readability-identifier-naming.VariableCase,        value: camelBack  }
 - { key: readability-identifier-naming.ParameterCase,       value: camelBack  }
 - { key: readability-identifier-naming.PublicMemberCase,    value: camelBack  }

# No good consensus on function names problem.isFinished() and GetInputFromUser() are both good
# - { key: readability-identifier-naming.FunctionCase,        value: camelBack  }
# - { key: readability-identifier-naming.PublicMethodCase,    value: camelBack  }
# - { key: readability-identifier-naming.PrivateMethodCase,   value: camelBack  }






########################################################################
# Disabled checks
########################################################################
# -fuchsia-*,
#     Checks associated with fuchsia operating system
# -cppcoreguidelines-owning-memory,
#      Using and learning about raw pointers, not type-based semantics of gsl::owner<T*>
# -cppcoreguidelines-pro-bounds-array-to-pointer-decay,
#      Using pointers to arrays
# -cppcoreguidelines-pro-bounds-pointer-arithmetic,
#      Not using <span> which is in C++20
# -google-build-using-namespace,
#      Will use "using namespace std" to make code easier to read
# -hicpp-no-array-decay,
#      Using pointers to arrays
# -modernize-use-trailing-return-type,
#      Not using the modern return type indications such as "factorial(int n) -> int"
# -llvm-header-guard
#      Will use short header guards not full directory and file name
# -cert-err60-cpp
#      Want to be able to throw exception with string
# -cppcoreguidelines-pro-bounds-constant-array-index
#      Want to use array[index] without having to use gsl::at()
# -google-global-names-in-headers
#      Readbility, want to have "using namespace std;" in headers as well
