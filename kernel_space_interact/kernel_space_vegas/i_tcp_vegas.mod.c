#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

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

KSYMTAB_FUNC(tcp_vegas_init, "_gpl", "");
KSYMTAB_FUNC(tcp_vegas_pkts_acked, "_gpl", "");
KSYMTAB_FUNC(tcp_vegas_state, "_gpl", "");
KSYMTAB_FUNC(tcp_vegas_cwnd_event, "_gpl", "");
KSYMTAB_FUNC(tcp_vegas_get_info, "_gpl", "");

SYMBOL_CRC(tcp_vegas_init, 0x7d0f4756, "_gpl");
SYMBOL_CRC(tcp_vegas_pkts_acked, 0xa85d3e6b, "_gpl");
SYMBOL_CRC(tcp_vegas_state, 0xd6fda27c, "_gpl");
SYMBOL_CRC(tcp_vegas_cwnd_event, 0x35933bb7, "_gpl");
SYMBOL_CRC(tcp_vegas_get_info, 0x1936c91a, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xdc50aae2, "__ref_stack_chk_guard" },
	{ 0x122c3a7e, "_printk" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xa916b694, "strnlen" },
	{ 0x19dee613, "__fortify_panic" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x1c303cee, "validate_usercopy_range" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xb4e02fb3, "tcp_register_congestion_control" },
	{ 0xab14bcb8, "proc_create" },
	{ 0x8eed1902, "tcp_unregister_congestion_control" },
	{ 0x3e00c634, "proc_remove" },
	{ 0x7192c2fe, "tcp_reno_cong_avoid" },
	{ 0x5625ef4d, "tcp_slow_start" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x362b796e, "tcp_reno_ssthresh" },
	{ 0xe530f9f7, "tcp_reno_undo_cwnd" },
	{ 0xa12905a6, "param_ops_int" },
	{ 0x7c15c4ff, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C3EE4389A9D01AA8A047FCB");
