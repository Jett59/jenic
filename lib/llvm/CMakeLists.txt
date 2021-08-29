find_package(llvm REQUIRED CONFIG)

message(STATUS "Found llvm version ${LLVM_PACKAGE_VERSION}")

add_library(Compiler compiler.cpp)

target_include_directories(Compiler PRIVATE ${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

llvm_map_components_to_libnames(llvm_libs support core irreader irwriter asmParser asmPrinter codegen)

target_link_libraries(Compiler ${llvm_libs})
