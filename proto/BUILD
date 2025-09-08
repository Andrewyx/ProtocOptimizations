load("@nanopb//extra/bazel:nanopb_cc_proto_library.bzl", "cc_nanopb_proto_library")
load("@protobuf//bazel:py_proto_library.bzl", "py_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")
load("//starlark:nanopb.bzl", "nanopb_proto_library")

package(default_visibility = ["//visibility:public"])

proto_library(
    name = "simple_proto",
    srcs = [":simple.proto"],
)

#cc_nanopb_proto_library(
#    name = "simple_cc_proto",
#    protos = [":simple_proto"],
#)

nanopb_proto_library(
    name = "simple_nanopb_proto",
    nanopb_libs = ["@nanopb//:nanopb"],
    options = glob(["*.options"]),
    deps = [":simple_proto"],
)
