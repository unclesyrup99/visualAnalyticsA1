{ pkgs }: {
    deps = [
        pkgs.openssh_with_kerberos
        pkgs.sudo
        pkgs.openssh_with_kerberos
        pkgs.cowsay
    ];
}