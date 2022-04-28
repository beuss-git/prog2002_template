cmake_minimum_required(VERSION 3.15)

project(LabXX)


add_executable(${PROJECT_NAME} src/main.cpp src/labxx.cpp src/labxx.hpp)

target_include_directories(${PROJECT_NAME} PRIVATE 
	${TCLAP_INCLUDE_DIR}
	${TESTER_INCLUDE_DIR}
	${GLFW_INCLUDE_DIR}
	${GLAD_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} TESTER glfw glad glm OpenGL::GL)
