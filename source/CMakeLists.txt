file(GLOB OUT *.cpp)

foreach (file ${OUT})
    get_filename_component(filename "${file}" NAME)
    add_executable(${filename} ${file})
endforeach ()

add_subdirectory(solutions)