add_executable(jenic main.cpp)

target_include_directories(jenic PUBLIC
"${PROJECT_BINARY_DIR}"
)

target_link_libraries(jenic Lexer Parser Collector)