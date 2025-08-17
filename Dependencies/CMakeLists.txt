project(Dependencies)

add_subdirectory(glad)
add_subdirectory(glfw)

add_library(${PROJECT_NAME} INTERFACE)

target_link_libraries(${PROJECT_NAME} INTERFACE
	glad
	glfw
)
