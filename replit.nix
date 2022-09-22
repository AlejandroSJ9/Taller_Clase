{ pkgs }: {
	deps = [
		pkgs.less
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}