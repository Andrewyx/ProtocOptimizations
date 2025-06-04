load("@protoc_deps//:requirements.bzl", "requirement")
load("@rules_proto//proto:defs.bzl", "proto_lang_toolchain")
load("@rules_python//python:pip.bzl", "compile_pip_requirements")

compile_pip_requirements(
    name = "protoc_requirements",
    src = "requirements.in",
    requirements_txt = "requirements_lock.txt",
)

# Configure protoc to have the right arguments for generating Python stubs.
# NB: the protobuf team intends to remove --python_out and instead use a protoc plugin for Python stub emit.
proto_lang_toolchain(
    name = "protoc_py_toolchain",
    command_line = "--python_out=%s",
    progress_message = "Generating Python proto_library %{label}",
    runtime = requirement("protobuf"),
)

# Adapters to the register_toolchains call, adding the toolchain_type to above
toolchain(
    name = "protoc_py_toolchain.registration",
    toolchain = ":protoc_py_toolchain",
    toolchain_type = "@rules_python//python/proto:toolchain_type",
)
