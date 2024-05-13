set(CMAKE_CXX_STANDARD 20)

file(GLOB src
	"*.cpp"
)

add_executable(RoboCrawler ${src})