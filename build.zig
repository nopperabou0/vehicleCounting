const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.resolveTargetQuery(.{ .os_tag = .linux, .cpu_arch = .x86_64, .abi = .gnu });
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "vehicleCounter",
        .target = target,
        .optimize = optimize,
    });

    exe.addCSourceFiles(.{ .files = &.{"./main.cpp"}, .flags = &.{ "-Wall", "-Wextra", "-pedantic", "-g3" } });

    exe.addIncludePath(b.path("."));

    exe.linkLibCpp();

    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);
}
