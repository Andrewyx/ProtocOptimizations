package(default_visibility = ["//visibility:public"])

cc_library(
    name = "main_headers",
    hdrs = ["main.h"],
    deps = [
        "//proto:simple_nanopb_proto",
    ],
)

# C++ binary that uses the nanopb library
cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        ":main_headers",
        "//proto:simple_nanopb_proto",
    ],
)
