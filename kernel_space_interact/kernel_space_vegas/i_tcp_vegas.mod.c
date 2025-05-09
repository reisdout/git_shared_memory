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

SYMBOL_CRC(tcp_vegas_init, 0x5a31fa1d, "_gpl");
SYMBOL_CRC(tcp_vegas_pkts_acked, 0x25a19275, "_gpl");
SYMBOL_CRC(tcp_vegas_state, 0x887608b4, "_gpl");
SYMBOL_CRC(tcp_vegas_cwnd_event, 0xb1e8090a, "_gpl");
SYMBOL_CRC(tcp_vegas_get_info, 0xdfbecf3e, "_gpl");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x122c3a7e, "_printk" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xa916b694, "strnlen" },
	{ 0x19dee613, "__fortify_panic" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x3da2baab, "tcp_register_congestion_control" },
	{ 0x20610fd0, "proc_create" },
	{ 0x84e1c19e, "tcp_unregister_congestion_control" },
	{ 0x57d21f86, "proc_remove" },
	{ 0xed2bd8aa, "tcp_reno_cong_avoid" },
	{ 0x59bfe352, "tcp_slow_start" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x039c8096, "tcp_reno_ssthresh" },
	{ 0x11c7642d, "tcp_reno_undo_cwnd" },
	{ 0xc1f869a6, "param_ops_int" },
	{ 0xef7c4e47, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "74B981538BD76453ABC79FD");
