dd if=/dev/zero of=disk.img bs=10M count=50
parted disk.img
parted disk.img mklabel gpt
parted disk.img mkpart uefi fat32 2048s 206848s
partx -a -v disk.img
mkfs.fat -F 32 /dev/loop0p1
mount /dev/loop0p1 efi/
mkdir -p efi/EFI/Boot/
cp bzImage efi/EFI/Boot/bootx64.efi
umount uefi
sync

apt --no-install-recommends -y install ovmf

qemu-system-x86_64 -enable-kvm -cpu host -drive if=pflash,format=raw,readonly=on,file=/usr/share/OVMF/OVMF_CODE_4M.fd -drive if=pflash,format=raw,file=/usr/share/OVMF/OVMF_VARS_4M.fd -smp "$(nproc)" -m 4g -drive file=/root/l1fd/disk.img,format=raw  -s
