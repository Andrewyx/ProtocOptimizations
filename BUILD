load("@nanopb//extra/bazel:nanopb_cc_proto_library.bzl", "cc_nanopb_proto_library")
load("@protobuf//bazel:proto_library.bzl", "proto_library")
load("@protobuf//bazel:py_proto_library.bzl", "py_proto_library")
load("@protoc_deps//:requirements.bzl", "requirement")

## Proto library definition
proto_library(
    name = "test_proto",
    srcs = ["test.proto"],
    deps = ["@nanopb//:nanopb_proto"],
)

cc_nanopb_proto_library(
    name = "nano_test",
    protos = ["test_proto"],
)

cc_proto_library(
    name = "test_cc_proto",
    deps = [":test_proto"],
)

## Python library for the proto
py_proto_library(
    name = "test_py_proto",
    visibility = ["//visibility:public"],
    deps = [
        ":test_proto",
        "@nanopb//:nanopb_proto",
    ],
)

#
## C++ binary that uses the nanopb library
cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "//:nano_test",
        #        "//test_subdir:nano_subdir_test",
    ],
)

# Python binary that uses the proto
py_binary(
    name = "main_python",
    srcs = ["main_python.py"],
    python_version = "PY3",
    deps = [
        "//:test_py_proto",
        #        requirement("protobuf"),
        "//test_subdir:subdir_test_py_proto",
    ],
)
