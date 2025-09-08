load("@nanopb//extra/bazel:nanopb_cc_proto_library.bzl", "cc_nanopb_proto_library")

package(default_visibility = ["//visibility:public"])

proto_library(
    name = "simple_proto",
    srcs = [":simple.proto"],
)

cc_nanopb_proto_library(
    name = "simple_nanopb_proto",
    protos = ["simple_proto"],
    copts = [
        "-DPB_FIELD_16BIT=1",
    ]
)
