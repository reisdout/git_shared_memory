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

SYMBOL_CRC(tcp_vegas_init, 0xd53349ce, "_gpl");
SYMBOL_CRC(tcp_vegas_pkts_acked, 0xa54d294b, "_gpl");
SYMBOL_CRC(tcp_vegas_state, 0x5c8282cd, "_gpl");
SYMBOL_CRC(tcp_vegas_cwnd_event, 0xf0175680, "_gpl");
SYMBOL_CRC(tcp_vegas_get_info, 0x0d3973db, "_gpl");

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
	"\x28\x00\x00\x00\x25\x12\x74\x9f"
	"tcp_register_congestion_control\0"
	"\x14\x00\x00\x00\xc2\xde\x7b\x8e"
	"proc_create\0"
	"\x2c\x00\x00\x00\xe6\xc2\x70\x76"
	"tcp_unregister_congestion_control\0\0\0"
	"\x14\x00\x00\x00\xbb\x98\x3b\x46"
	"proc_remove\0"
	"\x1c\x00\x00\x00\x2d\xba\x59\x84"
	"tcp_reno_cong_avoid\0"
	"\x18\x00\x00\x00\x86\xc7\x75\xfa"
	"tcp_slow_start\0\0"
	"\x2c\x00\x00\x00\xc6\xfa\xb1\x54"
	"__ubsan_handle_load_invalid_value\0\0\0"
	"\x1c\x00\x00\x00\x6a\x60\x6b\x9f"
	"tcp_reno_ssthresh\0\0\0"
	"\x1c\x00\x00\x00\x6e\x10\x7b\xd5"
	"tcp_reno_undo_cwnd\0\0"
	"\x18\x00\x00\x00\x4e\xc6\x24\xd8"
	"param_ops_int\0\0\0"
	"\x18\x00\x00\x00\x76\xf2\x0f\x5e"
	"module_layout\0\0\0"
	"\x00\x00\x00\x00\x00\x00\x00\x00";

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "41F92D6DAA7616F4031383F");
