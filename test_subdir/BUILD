load("@nanopb//extra/bazel:nanopb_cc_proto_library.bzl", "cc_nanopb_proto_library")
load("@protobuf//bazel:py_proto_library.bzl", "py_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

## Proto library definition
proto_library(
    name = "subdir_test_proto",
    srcs = ["subdir_test.proto"],
    deps = ["@nanopb//:nanopb_proto"],
)

## Python library for the proto
py_proto_library(
    name = "subdir_test_py_proto",
    visibility = ["//visibility:public"],
    deps = [":subdir_test_proto"],
)

cc_nanopb_proto_library(
    name = "nano_subdir_test",
    protos = ["subdir_test_proto"],
)
