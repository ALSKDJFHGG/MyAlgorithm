file(GLOB SRC_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

list(SORT SRC_SOURCES)

set(SRC_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/src")

foreach(SRC_SOURCE IN LISTS SRC_SOURCES)
    get_filename_component(SRC_NAME "${SRC_SOURCE}" NAME_WE)

    if(TARGET "${SRC_NAME}")
        message(FATAL_ERROR "Cannot create test target '${SRC_NAME}': a target with that name already exists")
    endif()

    add_executable("${SRC_NAME}" "${SRC_SOURCE}")

    set_target_properties("${SRC_NAME}" PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${SRC_OUTPUT_DIRECTORY}"
    )

    foreach(CONFIG IN LISTS CMAKE_CONFIGURATION_TYPES)
        string(TOUPPER "${CONFIG}" CONFIG_UPPER)
        set_target_properties("${SRC_NAME}" PROPERTIES
            "RUNTIME_OUTPUT_DIRECTORY_${CONFIG_UPPER}" "${HS_TEST_OUTPUT_DIRECTORY}"
        )
        
    endforeach()
    
    add_test(NAME "${SRC_NAME}" COMMAND "${SRC_NAME}")
    
endforeach()