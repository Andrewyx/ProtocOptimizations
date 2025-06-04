load("@nanopb//extra/bazel:nanopb_cc_proto_library.bzl", "cc_nanopb_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

## Proto library definition
proto_library(
    name = "subdir_test_proto",
    srcs = ["subdir_test.proto"],
    deps = ["@nanopb//:nanopb_proto"],
)

cc_nanopb_proto_library(
    name = "nano_subdir_test",
    protos = ["subdir_test_proto"],
)
