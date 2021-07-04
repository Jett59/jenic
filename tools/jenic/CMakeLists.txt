add_executable(jenic main.cpp)

#Include directories
target_include_directories(jenic PUBLIC
"${PROJECT_BINARY_DIR}"
)

target_link_libraries(jenic Lexer)