# shell.nix
{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  packages = with pkgs; [
    gcc
    clang
    llvm
    lld

    cmake
    meson
    ninja
    gnumake
    pkg-config

    gdb
    lldb
    valgrind

    clang-tools   # clangd, clang-format, clang-tidy
    cppcheck
    bear          # generate compile_commands.json
  ];

  shellHook = ''
    echo "🔧 C/C++ dev shell loaded"
  '';
}

