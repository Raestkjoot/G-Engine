project(Dependencies)

add_subdirectory(glad)
add_subdirectory(glfw)
add_subdirectory(glm)
add_subdirectory(stb)
add_subdirectory(imgui)
add_subdirectory(nfd)

add_library(${PROJECT_NAME} INTERFACE)

target_link_libraries(${PROJECT_NAME} INTERFACE
	glad
	glfw
	glm
	stb
	imgui
	nfd
)