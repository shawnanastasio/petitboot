
#include "parser-test.h"

#if 0 /* PARSER_EMBEDDED_CONFIG */
set default="test-option"
menuentry 'test-option' {
	linux   /vmlinux
}
#endif

void run_test(struct parser_test *test)
{
	struct discover_boot_option *opt;
	struct discover_context *ctx;

	test_read_conf_embedded(test, "/grub2/grub.cfg");
	test_run_parser(test, "grub2");

	ctx = test->ctx;

	check_boot_option_count(ctx, 1);
	opt = get_boot_option(ctx, 0);

	check_name(opt, "test-option");
	check_resolved_local_resource(opt->boot_image, ctx->device, "/vmlinux");
	check_is_default(opt);
}
