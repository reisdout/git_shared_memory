#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

KSYMTAB_FUNC(tcp_vegas_init, "_gpl", "");
KSYMTAB_FUNC(tcp_vegas_pkts_acked, "_gpl", "");
KSYMTAB_FUNC(tcp_vegas_state, "_gpl", "");
KSYMTAB_FUNC(tcp_vegas_cwnd_event, "_gpl", "");
KSYMTAB_FUNC(tcp_vegas_get_info, "_gpl", "");

SYMBOL_CRC(tcp_vegas_init, 0x1b459605, "_gpl");
SYMBOL_CRC(tcp_vegas_pkts_acked, 0xd0c4649f, "_gpl");
SYMBOL_CRC(tcp_vegas_state, 0x2e110878, "_gpl");
SYMBOL_CRC(tcp_vegas_cwnd_event, 0x2c3d9d5e, "_gpl");
SYMBOL_CRC(tcp_vegas_get_info, 0xf8d321da, "_gpl");

static const char ____versions[]
__used __section("__versions") =
	"\x14\x00\x00\x00\xbb\x6d\xfb\xbd"
	"__fentry__\0\0"
	"\x1c\x00\x00\x00\xca\x39\x82\x5b"
	"__x86_return_thunk\0\0"
	"\x10\x00\x00\x00\x7e\x3a\x2c\x12"
	"_printk\0"
	"\x18\x00\x00\x00\xc2\x9c\xc4\x13"
	"_copy_from_user\0"
	"\x10\x00\x00\x00\x94\xb6\x16\xa9"
	"strnlen\0"
	"\x18\x00\x00\x00\x8c\x89\xd4\xcb"
	"fortify_panic\0\0\0"
	"\x1c\x00\x00\x00\xcb\xf6\xfd\xf0"
	"__stack_chk_fail\0\0\0\0"
	"\x1c\x00\x00\x00\x48\x9f\xdb\x88"
	"__check_object_size\0"
	"\x18\x00\x00\x00\xe1\xbe\x10\x6b"
	"_copy_to_user\0\0\0"
	"\x28\x00\x00\x00\xac\xc9\x82\x2a"
	"tcp_register_congestion_control\0"
	"\x14\x00\x00\x00\xdc\x7a\x55\x83"
	"proc_create\0"
	"\x2c\x00\x00\x00\x31\x5a\xc7\x82"
	"tcp_unregister_congestion_control\0\0\0"
	"\x14\x00\x00\x00\xa8\x55\x13\xc4"
	"proc_remove\0"
	"\x18\x00\x00\x00\x17\x3b\x4d\x62"
	"tcp_slow_start\0\0"
	"\x1c\x00\x00\x00\x45\xe6\xd4\xab"
	"tcp_reno_cong_avoid\0"
	"\x1c\x00\x00\x00\xd6\xe3\x19\xed"
	"tcp_reno_ssthresh\0\0\0"
	"\x1c\x00\x00\x00\x05\xf0\x5b\xc6"
	"tcp_reno_undo_cwnd\0\0"
	"\x18\x00\x00\x00\xd9\x05\x9f\xc5"
	"param_ops_int\0\0\0"
	"\x18\x00\x00\x00\x41\x40\xb4\x0e"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BCEEE36C9FD16E1AFB8F3A2");
