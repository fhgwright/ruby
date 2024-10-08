#define COMMON_DIGEST_FOR_OPENSSL 1
#include <CommonCrypto/CommonDigest.h>

#ifdef __GNUC__
# define RB_DIGEST_DIAGNOSTIC(compiler, op, flag) _Pragma(STRINGIZE(compiler diagnostic op flag))
# ifdef RBIMPL_WARNING_IGNORED
#   define RB_DIGEST_WARNING_IGNORED(flag) RBIMPL_WARNING_IGNORED(flag)
# elif defined(__clang__)
#   define RB_DIGEST_WARNING_IGNORED(flag) RB_DIGEST_DIAGNOSTIC(clang, ignored, #flag)
# else /* __GNUC__ */
#   define RB_DIGEST_WARNING_IGNORED(flag) RB_DIGEST_DIAGNOSTIC(GCC, ignored, #flag)
# endif
RB_DIGEST_WARNING_IGNORED(-Wdeprecated-declarations)
/* Suppress deprecation warnings of MD5 from Xcode 11.1 */
/* Although we know MD5 is deprecated too, provide just for backward
 * compatibility, as well as Apple does. */
#endif

#define MD5_BLOCK_LENGTH	CC_MD5_BLOCK_BYTES

static DEFINE_UPDATE_FUNC_FOR_UINT(MD5)
static DEFINE_FINISH_FUNC_FROM_FINAL(MD5)

#undef MD5_Update
#undef MD5_Finish
#define MD5_Update rb_digest_MD5_update
#define MD5_Finish rb_digest_MD5_finish
